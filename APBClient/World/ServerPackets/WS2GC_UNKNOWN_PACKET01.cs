using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_UNKNOWN_PACKET01)]
        private class WS2GC_UNKNOWN_PACKET01 : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                byte unk1 = reader.ReadByte();
            }
        }
    }
}