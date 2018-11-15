﻿namespace APBClient.Networking
{
    internal enum APBOpCode : uint
    {
        GC2LS_ASK_LOGIN = 1000,
        GC2LS_LOGIN_PROOF = 1005,
        GC2LS_ASK_CHARACTER_INFO = 1006,
        GC2LS_ASK_WORLD_LIST = 1007,
        GC2LS_ASK_WORLD_ENTER = 1012,
        GC2LS_KEY_EXCHANGE = 1016,
        GC2LS_HARDWARE_INFO = 1017,

        LS2GC_ERROR = 2000,
        LS2GC_KICK = 2001,
        LS2GC_LOGIN_PUZZLE = 2002,
        LS2GC_LOGIN_SALT = 2003,
        LS2GC_ANS_LOGIN_SUCCESS = 2004,
        LS2GC_ANS_LOGIN_FAILED = 2005,
        LS2GC_CHARACTER_LIST = 2006,
        LS2GC_ANS_CHARACTER_INFO = 2007,
        LS2GC_ANS_WORLD_LIST = 2008,
        LS2GC_ANS_WORLD_ENTER = 2013,
        LS2GC_WMI_REQUEST = 2021,

        GC2WS_ASK_WORLD_ENTER = 3000,
        GC2WS_ASK_INSTANCE_LIST = 3002,
        GC2WS_ASK_DISTRICT_RESERVE = 3003,
        GC2WS_ASK_DISTRICT_ENTER = 3005,

        WS2GC_ANS_WORLD_ENTER = 4003,
        WS2GC_DISTRICT_LIST = 4006,
        WS2GC_ANS_INSTANCE_LIST = 4007,
        WS2GC_ANS_DISTRICT_RESERVE = 4008,
        WS2GC_ANS_DISTRICT_ENTER = 4010,
        WS2GC_CLAN_RANK_INFO = 4070,
        WS2GC_CLAN_INFO = 4071,
        WS2GC_CLAN_MOTD = 4072,
        WS2GC_VOICE_CHANNEL_INFO = 4114,

        //TODO
        WS2GC_FRIENDLIST_INFO = 4087, //m_nFriends, m_nCharacterUID[], m_szCharacterName[], m_nStatus[], m_nFaction[],
        WS2GC_CHALLENGE_OVERVIEW = 4127, //m_nNumChallenges 2, m_nDistrictUID 14, m_szRankedStatistic [activities], m_nMyRanking 0, m_nMyScore 0, m_dtChallengeEnd 2018/11/19 7:59:59, m_dtLastUpdated 2018/11/13 21:6:56, m_n1stScoreRequirement -10, m_n2ndScoreRequirement 15, m_n3rdScoreRequirement 7, m_n1stPercentageThreshold 9, m_n2ndPercentageThreshold 0, m_n3rdPercentageThreshold 0, m_n1stRedeemableRewardKey 19200, m_n2ndRedeemableRewardKey 19150, m_n3rdRedeemableRewardKey 19050, m_nTotalParticipants 0
        WS2GC_UNKNOWN_PACKET01 = 4082, //int,int,byte OR long,byte
        WS2GC_UNKNOWN_PACKET02 = 4105, //int,int,int,int,byte OR long,long,byte
    }
}