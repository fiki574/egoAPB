using System.Net;
using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_ANS_WORLD_ENTER)]
        private class LS2GC_ANS_WORLD_ENTER : BasePacketHandler<LobbyClient>
        {
            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                int returnCode = reader.ReadInt32();
                if (returnCode != 0)
                {
                    client.OnWorldEnterFailed(client, returnCode);
                    return;
                }

                var data = new WorldEnterData()
                {
                    ReturnCode = returnCode,
                    WorldServerIpAddress = new IPAddress(reader.ReadBytes(4)),
                    WorldServerPort = reader.ReadUInt16(),
                    Timestamp = reader.ReadUInt64(),
                    PingServerIpAddress = new IPAddress(reader.ReadBytes(4)),
                    Region = reader.ReadUnicodeString()
                };

                client.OnWorldEnterSuccess(client, data);
            }
        }
    }
}