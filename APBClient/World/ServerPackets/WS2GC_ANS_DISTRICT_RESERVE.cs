using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_ANS_DISTRICT_RESERVE)]
        private class WS2GC_ANS_DISTRICT_RESERVE : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                int returnCode = reader.ReadInt32();
                if (returnCode != 0)
                {
                    client.OnDistrictReserveFailed(client, returnCode);
                    return;
                }

                int temp = reader.ReadInt32();
                var info = new ReserveInfo()
                {
                    DistrictUid = temp << 8 >> 8,
                    InstanceNum = temp >> 24,
                    Group = reader.ReadBoolean(),
                    Queued = reader.ReadBoolean()
                };

                client.OnDistrictReserveSuccess(client, info);
            }
        }
    }
}