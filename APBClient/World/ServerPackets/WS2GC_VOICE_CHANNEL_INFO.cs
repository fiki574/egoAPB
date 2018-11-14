using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_VOICE_CHANNEL_INFO)]
        private class WS2GC_VOICE_CHANNEL_INFO : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                //m_sChannelUID %d, m_nChannelType %d, m_szChannelUri %S
            }
        }
    }
}