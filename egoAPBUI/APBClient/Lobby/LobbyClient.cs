using System;
using System.Collections.Generic;
using APBClient.Networking;
using Org.BouncyCastle.Crypto.Encodings;

namespace APBClient.Lobby
{
    public partial class LobbyClient : BaseClient
    {
        private byte[] SrpKey;
        private Pkcs1Encoding ClientDecryptEngine, ServerEncryptEngine;
        private HardwareStore HardwareStore;
        private string Username, Password;
        private uint AccountID;

        public event EventHandler<ErrorData> OnError = delegate { };
        public event EventHandler<int> OnPuzzleFailed = delegate { };
        public event EventHandler<LoginFailedData> OnLoginFailed = delegate { };
        public event EventHandler<EventArgs> OnLoginSuccess = delegate { };
        public event EventHandler<List<CharacterInfo>> OnCharacterList = delegate { };
        public event EventHandler<KickData> OnKick = delegate { };
        public event EventHandler<int> OnGetWorldListFailed = delegate { };
        public event EventHandler<List<WorldInfo>> OnGetWorldListSuccess = delegate { };
        public event EventHandler<int> OnWorldEnterFailed = delegate { };
        public event EventHandler<WorldEnterData> OnWorldEnterSuccess = delegate { };
        public event EventHandler<CharacterInfo.Detailed> OnGetCharacterInfoSuccess = delegate { };

        public LobbyClient(string username, string password, HardwareStore hw, ISocketFactory socketFactory = null) : base(socketFactory)
        {
            Username = username;
            Password = password;
            HardwareStore = hw;
        }

        public void EnterWorld(int characterSlotNumber)
        {
            var request = new GC2LS_ASK_WORLD_ENTER(characterSlotNumber);
            SendPacket(request);
        }

        public void GetWorldList()
        {
            var worldListReq = new GC2LS_ASK_WORLD_LIST();
            SendPacket(worldListReq);
        }

        public void GetDetailedCharacterInfo(int characterSlotNumber)
        {
            var infoReq = new GC2LS_ASK_CHARACTER_INFO(characterSlotNumber);
            SendPacket(infoReq);
        }

        public uint GetAccountId()
        {
            return AccountID;
        }

        public byte[] GetEncryptionKey()
        {
            return SrpKey;
        }
    }
}