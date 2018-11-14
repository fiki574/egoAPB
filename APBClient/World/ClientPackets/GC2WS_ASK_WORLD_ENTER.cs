using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        private class GC2WS_ASK_WORLD_ENTER : ClientPacket
        {
            public GC2WS_ASK_WORLD_ENTER(uint accountId, byte[] hash)
            {
                OpCode = (uint)APBOpCode.GC2WS_ASK_WORLD_ENTER;

                AllocateData(32);
                Writer.Write(accountId);
                Writer.Write(hash);
            }
        }
    }
}