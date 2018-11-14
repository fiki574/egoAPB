using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_CLAN_INFO)]
        private class WS2GC_CLAN_INFO : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                var info = new ClanInfo();
                info.Leader = reader.ReadInt32();
                info.Name = reader.ReadUnicodeString(66); //60
                info.Members = reader.ReadByte();
                info.ClanMembers = new ClanInfo.ClanMember[info.Members];
                for (int i = 0; i < info.Members; i++)
                {
                    info.ClanMembers[i] = new ClanInfo.ClanMember();
                    info.ClanMembers[i].Account = reader.ReadInt32();
                    info.ClanMembers[i].Character = reader.ReadInt32();
                    info.ClanMembers[i].Name = reader.ReadUnicodeString(31);
                    info.ClanMembers[i].Rank = reader.ReadInt32();
                    info.ClanMembers[i].Status = reader.ReadInt32();
                }
                client.OnGetClanInfoSuccess(client, info);
            }
        }
    }
}