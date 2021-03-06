﻿using System;
using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_ANS_CHARACTER_INFO)]
        private class LS2GC_ANS_CHARACTER_INFO : BasePacketHandler<LobbyClient>
        {
            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                var response = reader.ReadInt32();
                var data = new CharacterInfo.Detailed
                {
                    Slot = reader.ReadByte(),
                    Gender = (GenderType)reader.ReadByte(),
                    Playtime = reader.ReadUInt32(),
                    Rank = reader.ReadUInt32(),
                    Money = reader.ReadUInt32(),
                    JokerTickets = reader.ReadUInt32(),
                    Clan = reader.ReadUnicodeString(Constants.MAX_CLAN_NAME)
                };

                int size = packet.Data.Length - (int)reader.BaseStream.Position;
                byte[] appearance = new byte[size];
                int read = reader.Read(appearance, 0, size);
                if (read == size)
                {
                    data.Appearance = new byte[size - 18];
                    Buffer.BlockCopy(appearance, 18, data.Appearance, 0, size - 18);
                }
                else
                    data.Appearance = new byte[1] { 0x00 };

                client.OnGetCharacterInfoSuccess(client, data);
            }
        }
    }
}