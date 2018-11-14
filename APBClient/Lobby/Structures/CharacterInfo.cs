using System;

namespace APBClient.Lobby
{
    public class CharacterInfo
    {
        public enum FactionType : byte
        {
            Enforcer = 1,
            Criminal = 2
        }

        public enum ThreatType : byte
        {
            None = 0,
            Green = 1,
            Bronze = 2,
            Silver = 3,
            Gold = 4
        }

        public enum GenderType : byte
        {
            Male = 1,
            Female = 2
        }

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