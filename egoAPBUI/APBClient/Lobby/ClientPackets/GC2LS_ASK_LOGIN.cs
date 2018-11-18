using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        private class GC2LS_ASK_LOGIN : ClientPacket
        {
            public GC2LS_ASK_LOGIN(uint puzzleSolution, string email, byte loginType)
            {
                OpCode = (uint)APBOpCode.GC2LS_ASK_LOGIN;

                AllocateData(229);
                Writer.Write(puzzleSolution);
                Writer.Write(0);
                Writer.Write(0);
                Writer.Write(0);
                Writer.Write(0);
                Writer.Write(0);
                Writer.Write(loginType);
                Writer.WriteUnicodeString(email, 130);
                Writer.WriteUnicodeString("", 66);
            }
        }
    }
}