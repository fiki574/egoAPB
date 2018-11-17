using System;
using System.Collections.Generic;
using System.Reflection;
using System.Threading.Tasks;
using APBClient.Lobby;
using APBClient.Networking;
using APBClient.World;

namespace APBClient
{
    public class APBClient
    {
        interface IGenericTCS
        {
            void SetResult(object result);
            void SetTaskException(Exception e);
            Task BaseTask { get; }
        }

        class VirtualTCS<T> : IGenericTCS
        {
            private TaskCompletionSource<T> TCS;

            public VirtualTCS()
            {
                TCS = new TaskCompletionSource<T>();
            }

            public void SetResult(object result)
            {
                TCS.SetResult((T)result);
            }

            public void SetTaskException(Exception e)
            {
                Task<T> task = TCS.Task;
                if (task?.Status == TaskStatus.WaitingForActivation)
                    TCS.SetException(e);
            }

            public Task<T> Task => TCS.Task;
            public Task BaseTask => TCS.Task;
        }

        [AttributeUsage(AttributeTargets.Method)]
        public class RequiredStateAttribute : Attribute
        {
            public readonly ClientState RequiredState;

            public RequiredStateAttribute(ClientState requiredState)
            {
                RequiredState = requiredState;
            }
        }

        private const string LobbyHost = "apb.login.gamersfirst.com";
        private const int LobbyPort = 1001;

        private ISocketFactory SocketFactory;
        private LobbyClient LobbyClient;
        private WorldClient WorldClient;
        private ClientState State;
        private IGenericTCS ActiveTask;
        private List<CharacterInfo> Characters;
        private Dictionary<int, DistrictInfo> DistrictMap;
        private ClanInfo ClanInfo;
        private string ClanMOTD;
        private FriendlistInfo Friends;
        private IgnorelistInfo Ignores;
        private ChallengesInfo Challenges;
        private VoiceChannelInfo VoiceChannel;
        private MailInfo MailInfo;

        public APBClient(string username, string password, HardwareStore hw, ISocketFactory socketFactory = null)
        {
            SocketFactory = socketFactory;
            SetupLobbyClient(username, password, hw);
        }

        private EventHandler<T> GenerateEventHandler<T>(EventHandler<T> handler)
        {
            RequiredStateAttribute attribute = (RequiredStateAttribute)handler.Method.GetCustomAttribute(typeof(RequiredStateAttribute));
            if (attribute != null)
            {
                return (sender, e) =>
                {
                    if (EnsureState(attribute.RequiredState, $"{handler.Method.Name} called in unexpected state (Expected = {attribute.RequiredState}, Actual = {State})"))
                        handler(sender, e);
                };
            }
            else
                return handler;
        }

        private bool EnsureState(ClientState requiredState, string errMessage)
        {
            if (State != requiredState)
            {
                ActiveTask.SetTaskException(new Exception(errMessage));
                Disconnect();
                return false;
            }

            return true;
        }

        public void Disconnect()
        {
            State = ClientState.Disconnected;
            LobbyClient?.Disconnect();
            WorldClient?.Disconnect();
        }

        #region Lobby Client
        private void SetupLobbyClient(string username, string password, HardwareStore hw)
        {
            LobbyClient = new LobbyClient(username, password, hw, SocketFactory);
            LobbyClient.OnConnectSuccess += GenerateEventHandler<EventArgs>(HandleLobbyConnectSuccess);
            LobbyClient.OnDisconnect += GenerateEventHandler<EventArgs>(HandleLobbyDisconnect);
            LobbyClient.OnLoginSuccess += GenerateEventHandler<EventArgs>(HandleLoginSuccess);
            LobbyClient.OnCharacterList += GenerateEventHandler<List<CharacterInfo>>(HandleCharacterList);
            LobbyClient.OnGetWorldListSuccess += GenerateEventHandler<List<WorldInfo>>(HandleWorldListSuccess);
            LobbyClient.OnGetWorldListFailed += GenerateEventHandler<int>(HandleWorldListFailed);
            LobbyClient.OnWorldEnterSuccess += GenerateEventHandler<WorldEnterData>(HandleLobbyWorldEnterSuccess);
            LobbyClient.OnGetCharacterInfoSuccess += GenerateEventHandler<CharacterInfo.Detailed>(HandleLobbyGetInfo);
            Characters = null;
        }

        private void HandleLobbyDisconnect(object sender, EventArgs e)
        {
            if (State >= ClientState.LobbyServerWorldEnterComplete)
                return;

            State = ClientState.Disconnected;
            ActiveTask.SetTaskException(new Exception("Connection closed while processing"));
        }

        [RequiredState(ClientState.LobbyServerConnectInProgress)]
        private void HandleLobbyConnectSuccess(object sender, EventArgs e)
        {
            State = ClientState.LobbyServerLoginInProgress;
        }

        [RequiredState(ClientState.LobbyServerLoginInProgress)]
        private void HandleLoginSuccess(object sender, EventArgs e)
        {
            State = ClientState.LobbyServerLoginComplete;
        }

        [RequiredState(ClientState.LobbyServerLoginComplete)]
        private void HandleCharacterList(object sender, List<CharacterInfo> e)
        {
            State = ClientState.LobbyServerCharacterListReceived;
            Characters = e;
            ActiveTask?.SetResult(null);
        }

        [RequiredState(ClientState.LobbyServerWorldListInProgress)]
        private void HandleWorldListSuccess(object sender, List<WorldInfo> e)
        {
            State = ClientState.LobbyServerCharacterListReceived;
            ActiveTask?.SetResult(e);
        }

        [RequiredState(ClientState.LobbyServerWorldListInProgress)]
        private void HandleWorldListFailed(object sender, int e)
        {
            State = ClientState.LobbyServerCharacterListReceived;
            ActiveTask?.SetTaskException(new Exception($"Failed to retrieve world list (Return code = {e})"));
        }

        [RequiredState(ClientState.LobbyServerWorldEnterInProgress)]
        private void HandleLobbyWorldEnterSuccess(object sender, WorldEnterData e)
        {
            State = ClientState.LobbyServerWorldEnterComplete;
            SetupWorldClient(LobbyClient.GetEncryptionKey(), LobbyClient.GetAccountId(), e.Timestamp);
            State = ClientState.WorldServerConnectInProgress;
            WorldClient.Connect(e.WorldServerIpAddress.ToString(), e.WorldServerPort);
        }

        [RequiredState(ClientState.LobbyServerCharacterListReceived)]
        private void HandleLobbyGetInfo(object sender, CharacterInfo.Detailed e)
        {
            ActiveTask?.SetResult(e);
        }

        public Task Login()
        {
            if (State != ClientState.Disconnected)
                throw new InvalidOperationException("Client not in disconnected state");

            var tcs = new VirtualTCS<object>();
            ActiveTask = tcs;
            State = ClientState.LobbyServerConnectInProgress;
            LobbyClient.Connect(LobbyHost, LobbyPort);

            return tcs.Task;
        }

        public List<CharacterInfo> GetCharacters()
        {
            if (Characters == null)
                throw new InvalidOperationException("Client has not received characters yet");

            return Characters;
        }

        public Task<CharacterInfo.Detailed> GetDetailedCharacterInfo(int characterSlot)
        {
            if (State != ClientState.LobbyServerCharacterListReceived)
                throw new InvalidOperationException("Client has not received characters");

            var tcs = new VirtualTCS<CharacterInfo.Detailed>();
            ActiveTask = tcs;
            LobbyClient.GetDetailedCharacterInfo(characterSlot);
            return tcs.Task;
        }

        public Task<List<WorldInfo>> GetWorlds()
        {
            if (State != ClientState.LobbyServerCharacterListReceived)
                throw new InvalidOperationException("Client has not received characters");

            var tcs = new VirtualTCS<List<WorldInfo>>();
            ActiveTask = tcs;
            State = ClientState.LobbyServerWorldListInProgress;
            LobbyClient.GetWorldList();
            return tcs.Task;
        }

        public Task<FinalWorldEnterData> EnterWorld(int characterSlotNumber)
        {
            if (State != ClientState.LobbyServerCharacterListReceived)
                throw new InvalidOperationException("Client has not received characters or busy");

            var tcs = new VirtualTCS<FinalWorldEnterData>();
            ActiveTask = tcs;
            State = ClientState.LobbyServerWorldEnterInProgress;
            LobbyClient.EnterWorld(characterSlotNumber);
            return tcs.Task;
        }
        #endregion

        #region World Client
        private void SetupWorldClient(byte[] encryptionKey, uint accountId, ulong timestamp)
        {
            WorldClient = new WorldClient(encryptionKey, accountId, timestamp, SocketFactory);
            WorldClient.OnConnectSuccess += GenerateEventHandler<EventArgs>(HandleWorldConnectSuccess);
            WorldClient.OnDisconnect += GenerateEventHandler<EventArgs>(HandleWorldDisconnect);
            WorldClient.OnWorldEnterSuccess += GenerateEventHandler<FinalWorldEnterData>(HandleWorldEnterSuccess);
            WorldClient.OnInstanceListSuccess += GenerateEventHandler<List<InstanceInfo>>(HandleInstanceListSuccess);
            WorldClient.OnDistrictListSuccess += GenerateEventHandler<List<DistrictInfo>>(HandleDistrictListSuccess);
            WorldClient.OnDistrictReserveSuccess += GenerateEventHandler<ReserveInfo>(HandleDistrictReserveSuccess);
            WorldClient.OnDistrictReserveFailed += GenerateEventHandler<int>(HandleDistrictReserveFailed);
            WorldClient.OnDistrictEnterSuccess += GenerateEventHandler<DistrictEnterInfo>(HandleDistrictEnterSuccess);
            WorldClient.OnDistrictEnterFailed += GenerateEventHandler<int>(HandleDistrictEnterFailed);
            WorldClient.OnGetClanInfoSuccess += GenerateEventHandler<ClanInfo>(HandleGetClanInfoSuccess);
            WorldClient.OnGetClanMOTDSuccess += GenerateEventHandler<string>(HandleGetClanMOTDSuccess);
            WorldClient.OnGetFriendlistSuccess += GenerateEventHandler<FriendlistInfo>(HandleGetFriendlistSuccess);
            WorldClient.OnGetIgnorelistSuccess += GenerateEventHandler<IgnorelistInfo>(HandleGetIgnorelistSuccess);
            WorldClient.OnGetChallengesSuccess += GenerateEventHandler<ChallengesInfo>(HandleGetChallengesSuccess);
            WorldClient.OnGetVoiceChannelSuccess += GenerateEventHandler<VoiceChannelInfo>(HandleGetVoiceChannelSuccess);
            WorldClient.OnGetMailInfoSuccess += GenerateEventHandler<MailInfo>(HandleGetMailInfoSuccess);

            DistrictMap = null;
            ClanInfo = null;
            ClanMOTD = null;
            Friends = null;
            Ignores = null;
            Challenges = null;
            VoiceChannel = null;
            MailInfo = null;
        }

        private void HandleWorldDisconnect(object sender, EventArgs e)
        {
            State = ClientState.Disconnected;
            ActiveTask?.SetTaskException(new Exception("Connection closed while processing"));
        }

        [RequiredState(ClientState.WorldServerConnectInProgress)]
        private void HandleWorldConnectSuccess(object sender, EventArgs e)
        {
            State = ClientState.WorldServerConnectComplete;
        }

        [RequiredState(ClientState.WorldServerConnectComplete)]
        private void HandleDistrictListSuccess(object sender, List<DistrictInfo> e)
        {
            DistrictMap = new Dictionary<int, DistrictInfo>();
            foreach (DistrictInfo district in e)
                DistrictMap[district.DistrictUid] = district;
        }

        [RequiredState(ClientState.WorldServerConnectComplete)]
        private void HandleGetClanInfoSuccess(object sender, ClanInfo e)
        {
            ClanInfo = e;
        }

        [RequiredState(ClientState.WorldServerConnectComplete)]
        private void HandleGetClanMOTDSuccess(object sender, string e)
        {
            ClanMOTD = e;
        }

        [RequiredState(ClientState.WorldServerConnectComplete)]
        private void HandleGetFriendlistSuccess(object sender, FriendlistInfo e)
        {
            Friends = e;
        }

        [RequiredState(ClientState.WorldServerConnectComplete)]
        private void HandleGetIgnorelistSuccess(object sender, IgnorelistInfo e)
        {
            Ignores = e;
        }

        [RequiredState(ClientState.WorldServerConnectComplete)]
        private void HandleGetChallengesSuccess(object sender, ChallengesInfo e)
        {
            Challenges = e;
        }

        [RequiredState(ClientState.WorldServerConnectComplete)]
        private void HandleGetVoiceChannelSuccess(object sender, VoiceChannelInfo e)
        {
            VoiceChannel = e;
        }

        [RequiredState(ClientState.WorldServerConnectComplete)]
        private void HandleGetMailInfoSuccess(object sender, MailInfo e)
        {
            MailInfo = e;
        }

        [RequiredState(ClientState.WorldServerConnectComplete)]
        private void HandleWorldEnterSuccess(object sender, FinalWorldEnterData e)
        {
            State = ClientState.WorldServerWorldEnterComplete;
            ActiveTask?.SetResult(e);
        }

        [RequiredState(ClientState.WorldServerInstanceListInProgress)]
        private void HandleInstanceListSuccess(object sender, List<InstanceInfo> e)
        {
            State = ClientState.WorldServerWorldEnterComplete;
            ActiveTask?.SetResult(e);
        }

        [RequiredState(ClientState.WorldServerDistrictReserveInProgress)]
        private void HandleDistrictReserveSuccess(object sender, ReserveInfo reserveInfo)
        {
            WorldClient.AskDistrictEnter();
            State = ClientState.WorldServerDistrictEnterInProgress;
        }

        [RequiredState(ClientState.WorldServerDistrictReserveInProgress)]
        private void HandleDistrictReserveFailed(object sender, int e)
        {
            State = ClientState.WorldServerWorldEnterComplete;
            ActiveTask?.SetTaskException(new Exception($"Failed to reserve district (Error Code = {e})"));
        }

        [RequiredState(ClientState.WorldServerDistrictEnterInProgress)]
        private void HandleDistrictEnterSuccess(object sender, DistrictEnterInfo enterInfo)
        {
            State = ClientState.WorldServerDistrictEnterComplete;
            ActiveTask?.SetResult(enterInfo);
        }

        [RequiredState(ClientState.WorldServerDistrictEnterInProgress)]
        private void HandleDistrictEnterFailed(object send, int e)
        {
            State = ClientState.WorldServerWorldEnterComplete;
            ActiveTask?.SetTaskException(new Exception($"Failed to enter district (Error Code = {e})"));
        }

        public Dictionary<int, DistrictInfo> GetDistricts()
        {
            if (DistrictMap == null)
                throw new InvalidOperationException("No district map");

            return DistrictMap;
        }

        public ClanInfo GetClanInfo()
        {
            if (ClanInfo == null)
                throw new InvalidOperationException("No clan info");

            return ClanInfo;
        }

        public string GetClanMOTD()
        {
            if (ClanMOTD == null)
                throw new InvalidOperationException("No MOTD");

            return ClanMOTD;
        }

        public FriendlistInfo GetFriendList()
        {
            if (Friends == null)
                throw new InvalidOperationException("No friends");

            return Friends;
        }

        public IgnorelistInfo GetIgnoreList()
        {
            if (Ignores == null)
                throw new InvalidOperationException("No ignores");

            return Ignores;
        }

        public ChallengesInfo GetChallenges()
        {
            if (Challenges == null)
                throw new InvalidOperationException("No challenges");

            return Challenges;
        }

        public VoiceChannelInfo GetVoiceChannel()
        {
            if (VoiceChannel == null)
                throw new InvalidOperationException("No voice channel");

            return VoiceChannel;
        }

        public MailInfo GetMailInfo()
        {
            if (MailInfo == null)
                throw new InvalidOperationException("No mails");

            return MailInfo;
        }

        public Task<List<InstanceInfo>> GetInstances()
        {
            if (State != ClientState.WorldServerWorldEnterComplete)
                throw new InvalidOperationException("Client has not entered world");

            var tcs = new VirtualTCS<List<InstanceInfo>>();
            ActiveTask = tcs;
            State = ClientState.WorldServerInstanceListInProgress;
            WorldClient.GetInstanceList();
            return tcs.Task;
        }

        public Task<DistrictEnterInfo> JoinInstance(InstanceInfo instance)
        {
            if (State != ClientState.WorldServerWorldEnterComplete)
                throw new InvalidOperationException("Client has not entered world");

            var tcs = new VirtualTCS<DistrictEnterInfo>();
            ActiveTask = tcs;
            State = ClientState.WorldServerDistrictReserveInProgress;
            WorldClient.AskDistrictReserve(instance.DistrictUid, instance.InstanceNum, -1, false);
            return tcs.Task;
        }
        #endregion
    }
}