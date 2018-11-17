using System;
using APBClient.World;

namespace APBClient.Lobby
{
    public class CharacterInfo
    {
        public int SlotNumber;
        public FactionType Faction;
        public StatusType WorldStatus;
        public int WorldUID;
        public string WorldName;
        public string CharacterName;
        public int Rating;
        public DateTime LastLogin;
        public ThreatType Threat;
        public Detailed Details;
        public ClanInfo Clan;
        public FriendlistInfo Friends;
        public IgnorelistInfo Ignores;
        public FinalWorldEnterData WorldEnterData;
        public ChallengesInfo ChallengesInfo;
        public MailInfo MailsInfo;

        public class Detailed
        {
            public byte Slot;
            public GenderType Gender;
            public uint Playtime;
            public uint Rank;
            public uint Money;
            public uint JokerTickets;
            public string Clan;
            public byte[] Appearance;
        }
    }
}