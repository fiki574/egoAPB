using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        private class GC2LS_KEY_EXCHANGE : ClientPacket
        {
            public GC2LS_KEY_EXCHANGE(byte[] encryptedKey)
            {
                OpCode = (uint)APBOpCode.GC2LS_KEY_EXCHANGE;

                AllocateData(268);
                Writer.Write(0);
                Writer.Write(encryptedKey);
            }
        }
    }
}