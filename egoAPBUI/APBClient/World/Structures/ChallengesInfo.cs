using System;

namespace APBClient.World
{
    public class ChallengesInfo
    {
        public int TotalChallenges;
        public Challenge[] Challenges;

        public class Challenge
        {
            public int District;
            public string Name;
            public int MyRanking;
            public int MyScore;
            public DateTime LastUpdate;
            public DateTime EndDate;
            public int FirstScoreRequirement;
            public int SecondScoreRequirement;
            public int ThirdScoreRequirement;
            public int FirstPercentageThreshold;
            public int SecondPercentageThreshold;
            public int ThirdPercentageThreshold;
            public int FirstRedeemableRewardKey;
            public int SecondRedeemableRewardKey;
            public int ThirdRedeemableRewardKey;
            public int TotalParticipants;
        }
    }
}