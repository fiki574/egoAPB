namespace APBClient.World
{
    public class FriendlistInfo
    {
        public int TotalFriends;
        public Friend[] Friends;

        public class Friend
        {
            public int CharacterID;
            public string Name;
            public StatusType Status;
            public FactionType Faction;
        }
    }
}