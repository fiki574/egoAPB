using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_CLAN_RANK_INFO)]
        private class WS2GC_CLAN_RANK_INFO : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                int ranks = reader.ReadByte();
                for(int i = 0; i < ranks; i++)
                {
                    int uid = reader.ReadInt32();
                    string name = reader.ReadUnicodeString(16);
                    reader.BaseStream.Position += 22;
                }
            }
        }
    }
}