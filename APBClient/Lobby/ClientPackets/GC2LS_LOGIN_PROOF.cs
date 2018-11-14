using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        private class GC2LS_LOGIN_PROOF : ClientPacket
        {
            public GC2LS_LOGIN_PROOF(byte[] clientPub, byte[] proof)
            {
                OpCode = (uint)APBOpCode.GC2LS_LOGIN_PROOF;

                AllocateData(94);
                Writer.Write(clientPub);
                for (int i = clientPub.Length; i < 64; i++)
                    Writer.Write(0);

                Writer.Write((ushort) clientPub.Length);
                Writer.Write(proof);
                for (int i = proof.Length; i < 20; i++)
                    Writer.Write(0);
            }
        }
    }
}