using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_CLAN_MOTD)]
        private class WS2GC_CLAN_MOTD : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                string motd = reader.ReadUnicodeString();
                client.OnGetClanMOTDSuccess(client, motd);
            }
        }
    }
}