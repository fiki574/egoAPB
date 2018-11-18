using APBClient.Networking;
using System;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_CHALLENGE_OVERVIEW)]
        private class WS2GC_CHALLENGE_OVERVIEW : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                var challenge = new ChallengesInfo();
                challenge.TotalChallenges = reader.ReadInt32();
                challenge.Challenges = new ChallengesInfo.Challenge[challenge.TotalChallenges];
                for(int i = 0; i < challenge.TotalChallenges; i++)
                {
                    challenge.Challenges[i] = new ChallengesInfo.Challenge();
                    challenge.Challenges[i].District = reader.ReadInt32();
                    reader.Skip(4);
                    challenge.Challenges[i].Name = reader.ReadUnicodeString(Constants.MAX_CHALLENGE_NAME);
                    reader.Skip(36);
                    challenge.Challenges[i].MyRanking = reader.ReadInt32();
                    challenge.Challenges[i].MyScore = reader.ReadInt32();
                    challenge.Challenges[i].LastUpdate = new DateTime(reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16());
                    reader.Skip(4);
                    challenge.Challenges[i].EndDate = new DateTime(reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16(), reader.ReadInt16());
                    reader.Skip(4);
                    challenge.Challenges[i].FirstScoreRequirement = reader.ReadInt32();
                    challenge.Challenges[i].SecondScoreRequirement = reader.ReadInt32();
                    challenge.Challenges[i].ThirdScoreRequirement = reader.ReadInt32();
                    challenge.Challenges[i].FirstPercentageThreshold = reader.ReadInt32();
                    challenge.Challenges[i].SecondPercentageThreshold = reader.ReadInt32();
                    challenge.Challenges[i].ThirdPercentageThreshold = reader.ReadInt32();
                    challenge.Challenges[i].FirstRedeemableRewardKey = reader.ReadInt32();
                    challenge.Challenges[i].SecondRedeemableRewardKey = reader.ReadInt32();
                    challenge.Challenges[i].ThirdRedeemableRewardKey = reader.ReadInt32();
                    challenge.Challenges[i].TotalParticipants = reader.ReadInt32();
                }
                client.OnGetChallengesSuccess(client, challenge);
            }
        }
    }
}