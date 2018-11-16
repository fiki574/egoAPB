using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_FRIENDLIST_INFO)]
        private class WS2GC_FRIENDLIST_INFO : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                var friends = new FriendlistInfo();
                friends.TotalFriends = reader.ReadByte();
                friends.Friends = new FriendlistInfo.Friend[friends.TotalFriends];
                for(int i = 0; i < friends.TotalFriends; i++)
                {
                    friends.Friends[i] = new FriendlistInfo.Friend();
                    friends.Friends[i].CharacterID = reader.ReadInt32();
                    friends.Friends[i].Name = reader.ReadUnicodeString(34);
                    friends.Friends[i].Status = (StatusType)reader.ReadByte();
                    friends.Friends[i].Faction = (FactionType)reader.ReadByte();
                }
                client.OnGetFriendlistSuccess(client, friends);
            }
        }
    }
}