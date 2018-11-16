using System;
using System.Collections.Generic;
using APBClient.Networking;
using Org.BouncyCastle.Crypto.Digests;

namespace APBClient.World
{
    public partial class WorldClient : BaseClient
    {
        public event EventHandler<ErrorData> OnError = delegate { };
        public event EventHandler<KickData> OnKick = delegate { };
        public event EventHandler<FinalWorldEnterData> OnWorldEnterSuccess = delegate { };
        public event EventHandler<int> OnWorldEnterFailed = delegate { };
        public event EventHandler<List<InstanceInfo>> OnInstanceListSuccess = delegate { };
        public event EventHandler<int> OnInstanceListFailed = delegate { };
        public event EventHandler<List<DistrictInfo>> OnDistrictListSuccess = delegate { };
        public event EventHandler<int> OnDistrictReserveFailed = delegate { };
        public event EventHandler<ReserveInfo> OnDistrictReserveSuccess = delegate { };
        public event EventHandler<int> OnDistrictEnterFailed = delegate { };
        public event EventHandler<DistrictEnterInfo> OnDistrictEnterSuccess = delegate { };
        public event EventHandler<ClanInfo> OnGetClanInfoSuccess = delegate { };
        public event EventHandler<string> OnGetClanMOTDSuccess = delegate { };
        public event EventHandler<FriendlistInfo> OnGetFriendlistSuccess = delegate { };
        public event EventHandler<IgnorelistInfo> OnGetIgnorelistSuccess = delegate { };
        public event EventHandler<ChallengesInfo> OnGetChallengesSuccess = delegate { };

        private byte[] EncryptionKey;
        private uint AccountID;
        private ulong Timestamp;

        public WorldClient(byte[] encryptionKey, uint accountId, ulong timestamp, ISocketFactory socketFactory = null) : base(socketFactory)
        {
            EncryptionKey = encryptionKey;
            AccountID = accountId;
            Timestamp = timestamp;
        }

        protected override void PostConnect()
        {
            var sha1 = new Sha1Digest();
            sha1.BlockUpdate(EncryptionKey, 0, EncryptionKey.Length);
            sha1.BlockUpdate(BitConverter.GetBytes(Timestamp), 0, 8);
            var hash = new byte[sha1.GetDigestSize()];
            sha1.DoFinal(hash, 0);
            var req = new GC2WS_ASK_WORLD_ENTER(AccountID, hash);
            SendPacket(req);
            SetEncryptionKey(EncryptionKey);
        }

        public void GetInstanceList()
        {
            var instanceListReq = new GC2WS_ASK_INSTANCE_LIST();
            SendPacket(instanceListReq);
        }

        public void AskDistrictReserve(int districtUid, int instanceNum, int characterUid, bool group)
        {
            SendPacket(new GC2WS_ASK_DISTRICT_RESERVE(districtUid, instanceNum, characterUid, group));
        }

        public void AskDistrictEnter()
        {
            SendPacket(new GC2WS_ASK_DISTRICT_ENTER());
        }
    }
}