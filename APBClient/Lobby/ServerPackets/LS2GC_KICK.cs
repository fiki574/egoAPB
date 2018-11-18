using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_KICK)]
        private class LS2GC_KICK : BasePacketHandler<LobbyClient>
        {
            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                var data = new KickData
                {
                    Reason = reader.ReadUInt32(),
                    Information = reader.ReadUnicodeString()
                };

                client.OnKick(client, data);
                client.Disconnect();
            }
        }
    }
}