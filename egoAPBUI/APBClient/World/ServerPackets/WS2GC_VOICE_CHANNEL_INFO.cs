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

                var vci = new VoiceChannelInfo()
                {
                    ID = reader.ReadInt64(),
                    Type = reader.ReadInt32(),
                    URI = reader.ReadASCIIString(packet.Data.Length - (int)reader.BaseStream.Position)
                };
                client.OnGetVoiceChannelSuccess(client, vci);
            }
        }
    }
}