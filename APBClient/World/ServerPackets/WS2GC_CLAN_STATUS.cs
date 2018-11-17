using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_CLAN_STATUS)]
        private class WS2GC_CLAN_STATUS : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                int charuid = reader.ReadInt32();
                byte status = reader.ReadByte();
            }
        }
    }
}