﻿using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_ANS_WORLD_ENTER)]
        private class WS2GC_ANS_WORLD_ENTER : BasePacketHandler<WorldClient>
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

                var data = new FinalWorldEnterData
                { 
                    ReturnCode = returnCode,
                    CharacterUid = reader.ReadUInt32(),
                    ServerTime = reader.ReadUInt64(),
                    MarketplaceMinimumBidPercentage = reader.ReadSingle(),
                    GroupPublic = reader.ReadByte(),
                    GroupInvite = reader.ReadByte(),
                    ConfigFileVersion = new[] { reader.ReadInt32(), reader.ReadInt32(), reader.ReadInt32(), reader.ReadInt32(), reader.ReadInt32() },
                    TutorialComplete = reader.ReadBoolean(),
                    LookingForGroup = reader.ReadBoolean(),
                    AvailableForMetagrouping = reader.ReadBoolean(),
                    ThreatLevel = reader.ReadByte(),
                    UtcOffset = reader.ReadInt16()
                };

                client.OnWorldEnterSuccess(client, data);
            }
        }
    }
}