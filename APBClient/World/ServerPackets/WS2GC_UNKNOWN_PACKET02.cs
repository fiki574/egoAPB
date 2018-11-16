using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_UNKNOWN_PACKET02)]
        private class WS2GC_UNKNOWN_PACKET02 : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                int unk1 = reader.ReadInt32();
                int unk2 = reader.ReadInt32();
                byte unk3 = reader.ReadByte();
            }
        }
    }
}