namespace APBClient.World
{
    public class ClanInfo
    {
        public int Leader;
        public string Name;
        public int Members;
        public ClanMember[] ClanMembers;
        public string MOTD;

        public class ClanMember
        {
            public int Account;
            public int Character;
            public string Name;
            public int Rank;
            public StatusType Status;
        }
    }
}