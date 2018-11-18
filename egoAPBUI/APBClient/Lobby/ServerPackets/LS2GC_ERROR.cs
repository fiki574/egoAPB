using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_ERROR)]
        private class LS2GC_ERROR : BasePacketHandler<LobbyClient>
        {
            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                var data = new ErrorData
                {
                    MessageId = reader.ReadUInt32(),
                    QueryId = reader.ReadUInt16(),
                    ReturnCode = reader.ReadUInt32(),
                    Param1 = reader.ReadUInt32(),
                    Param2 = reader.ReadUInt32(),
                    Param3 = reader.ReadUInt32(),
                    Param4 = reader.ReadUInt32()
                };

                client.OnError(client, data);
                client.Disconnect();
            }
        }
    }
}