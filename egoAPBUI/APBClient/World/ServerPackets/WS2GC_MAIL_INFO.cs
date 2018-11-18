using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_MAIL_INFO)]
        private class WS2GC_MAIL_INFO : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                var mails = new MailInfo()
                {
                    Type = reader.ReadByte(),
                    Total = reader.ReadInt32(),
                    Unread = reader.ReadInt32(),
                    Expired = reader.ReadInt32()
                };
                client.OnGetMailInfoSuccess(client, mails);
            }
        }
    }
}