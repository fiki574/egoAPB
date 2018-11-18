﻿namespace APBClient.World
{
    public class FinalWorldEnterData
    {
        public int ReturnCode;
        public uint CharacterUid;
        public ulong ServerTime;
        public float MarketplaceMinimumBidPercentage;
        public byte GroupPublic;
        public byte GroupInvite;
        public int[] ConfigFileVersion;
        public bool TutorialComplete;
        public bool LookingForGroup;
        public bool AvailableForMetagrouping;
        public byte ThreatLevel;
        public short UtcOffset;
    }
}