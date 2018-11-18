using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        private class GC2WS_ASK_DISTRICT_RESERVE : ClientPacket
        {
            public GC2WS_ASK_DISTRICT_RESERVE(int districtUid, int instanceNum, int characterUid, bool group)
            {
                OpCode = (uint)APBOpCode.GC2WS_ASK_DISTRICT_RESERVE;

                AllocateData(17);
                Writer.Write((instanceNum << 24) | (districtUid & 0xFFFFFF));
                Writer.Write(characterUid);
                Writer.Write(group);
            }
        }
    }
}