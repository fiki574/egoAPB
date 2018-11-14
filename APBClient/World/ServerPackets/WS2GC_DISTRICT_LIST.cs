using System.Collections.Generic;
using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_DISTRICT_LIST)]
        private class WS2GC_DISTRICT_LIST : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                int returnCode = reader.ReadInt32();
                if (returnCode != 0)
                {
                    client.OnWorldEnterFailed(client, returnCode);
                    return;
                }

                short numDistricts = reader.ReadInt16();
                var districts = new List<DistrictInfo>();
                for (int i = 0; i < numDistricts; i++)
                {
                    districts.Add(new DistrictInfo
                    {
                        DistrictUid = reader.ReadInt32(),
                        DistrictInstanceTypeSdd = reader.ReadUInt32()
                    });
                }
                client.OnDistrictListSuccess(client, districts);
            }
        }
    }
}