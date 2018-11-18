using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        private class GC2LS_ASK_CHARACTER_INFO : ClientPacket
        {
            public GC2LS_ASK_CHARACTER_INFO(int characterSlot)
            {
                OpCode = (uint)APBOpCode.GC2LS_ASK_CHARACTER_INFO;

                AllocateData(9);
                Writer.Write((byte)characterSlot);
            }
        }
    }
}