using System;

namespace APBClient.Lobby
{
    public class CharacterInfo
    {
        public int SlotNumber;
        public FactionType Faction;
        public int WorldStatus;
        public int WorldUID;
        public string WorldName;
        public string CharacterName;
        public int Rating;
        public DateTime LastLogin;
        public ThreatType Threat;

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