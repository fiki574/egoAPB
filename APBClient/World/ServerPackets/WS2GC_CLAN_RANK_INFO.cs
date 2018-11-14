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
                //m_nRanks %d, m_nRankUID[%d] %d, m_szRankName[%d] %s, m_nPermission[%d] 0x%08x
            }
        }
    }
}