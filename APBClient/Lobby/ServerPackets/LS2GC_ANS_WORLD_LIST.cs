using System.Collections.Generic;
using System.Net;
using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_ANS_WORLD_LIST)]
        private class LS2GC_ANS_WORLD_LIST : BasePacketHandler<LobbyClient>
        {
            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                int returnCode = reader.ReadInt32();
                if (returnCode != 0)
                {
                    client.OnGetWorldListFailed(client, returnCode);
                    return;
                }

                int numWorlds = reader.ReadInt16();
                var worlds = new List<WorldInfo>(numWorlds);

                for (int i = 0; i < numWorlds; i++)
                {
                    var info = new WorldInfo
                    {
                        Uid = reader.ReadInt32(),
                        Name = reader.ReadUnicodeString(34),
                        Status = (WorldInfo.StatusType)reader.ReadByte(),
                        Population = reader.ReadByte(),
                        EnfFaction = reader.ReadByte(),
                        CrimFaction = reader.ReadByte(),
                        PremiumOnly = reader.ReadByte(),
                        Region = reader.ReadUnicodeString(),
                        PingIp = new IPAddress(reader.ReadBytes(4))
                    };
                    worlds.Add(info);
                }

                client.OnGetWorldListSuccess(client, worlds);
            }
        }
    }
}