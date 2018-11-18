using APBClient.Networking;

namespace APBClient.World
{
    class GC2WS_ASK_DISTRICT_ENTER : ClientPacket
    {
        public GC2WS_ASK_DISTRICT_ENTER()
        {
            OpCode = (uint)APBOpCode.GC2WS_ASK_DISTRICT_ENTER;

            AllocateData(9);
            Writer.Write((byte)0);
        }
    }
}