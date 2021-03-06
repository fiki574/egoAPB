﻿using System;
using System.Collections.Generic;
using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_CHARACTER_LIST)]
        private class LS2GC_CHARACTER_LIST : BasePacketHandler<LobbyClient>
        {
            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                byte numCharacters = reader.ReadByte();
                int numAdditionalSlots = reader.ReadInt32();
                byte accountThreat = reader.ReadByte();
                var characters = new List<CharacterInfo>(numCharacters);
                for (int i = 0; i < numCharacters; i++)
                {
                    var info = new CharacterInfo
                    {
                        SlotNumber = reader.ReadByte(),
                        Faction = (FactionType)reader.ReadByte(),
                        WorldStatus = (StatusType)reader.ReadByte(),
                        WorldUID = reader.ReadInt32(),
                        WorldName = reader.ReadUnicodeString(Constants.MAX_WORLD_NAME),
                        CharacterName = reader.ReadUnicodeString(Constants.MAX_CHARACTER_NAME),
                        Rating = reader.ReadInt32(),
                        LastLogin = new DateTime(reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16()),
                        Threat = (ThreatType)accountThreat
                    };
                    reader.ReadInt32();
                    characters.Add(info);
                }
                client.OnCharacterList(client, characters);
            }
        }
    }
}