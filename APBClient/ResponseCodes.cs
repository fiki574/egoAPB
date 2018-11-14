﻿namespace APBClient
{
    public enum ResponseCodes : int
    {
        RC_SUCCESS = 0,
        RC_FAILED = 1,
        RC_INVALID_MESSAGE = 2,
        RC_INVALID_STATUS = 3,
        RC_DATABASE_ERROR = 4,
        RC_DATABASE_BUSY = 5,
        RC_MESSAGE_FLOOD = 6,
        RC_DATABASE_QUERY_TIMEOUT = 7,
        RC_CONNECT_FAILED = 8,
        RC_DISCONNECTED = 9,
        RC_UE3_CLIENT_SERVER_MISMATCH = 10,
        RC_DATABASE_PENDING = -1,
        RC_TIMEOUT = 12,
        RC_SESSION_CHANGED = 13,
        RC_DATABASE_UNEXPECTED_RC_START = 11,
        KICK_REASON_DUPLICATE_LOGIN = 1,
        KICK_REASON_GM = 2,
        KICK_REASON_SUBSCRIPTION_EXPIRED = 3,
        KICK_REASON_PUNKBUSTER = 4,
        RC_LOGIN_INVALID_VERSION = 10001,
        RC_LOGIN_INVALID_ACCOUNT = 10002,
        RC_LOGIN_INVALID_PASSWORD = 10003,
        RC_LOGIN_ACCOUNT_IN_USE = 10004,
        RC_LOGIN_LOGIN_IN_PROGRESS = 10005,
        RC_LOGIN_ACCOUNT_NOT_ALLOWED = 10006,
        RC_LOGIN_ACCOUNT_TYPE_BLOCKED = 10007,
        RC_LOGIN_ACCOUNT_BLOCKED = 10008,
        RC_LOGIN_SESSION_TIMEOUT = 10009,
        RC_LOGIN_INVALID_INFORMATION = 10010,
        RC_LOGIN_INVALID_SOLUTION = 10011,
        RC_LOGIN_NO_SESSION = 10012,
        RC_LOGIN_APB_INACTIVATED = 10013,
        RC_CHARACTER_NAME_CHECK_IN_USE = 20001,
        RC_CHARACTER_NAME_CHECK_BAD_NAME = 20002,
        RC_CHARACTER_NAME_CHECK_INVALID_NAME = 20004,
        RC_CHARACTER_CREATE_NAME_IN_USE = 30001,
        RC_CHARACTER_CREATE_NAME_NOT_CHECKED = 30002,
        RC_CHARACTER_CREATE_INVALID_CUSTOMISATION = 30003,
        RC_CHARACTER_CREATE_WORLD_FULL = 30004,
        RC_CHARACTER_CREATE_CHARACTER_LIMIT = 30006,
        RC_CHARACTER_CREATE_WORLD_OFFLINE = 30007,
        RC_CHARACTER_DELETE_INVALID_SLOT_NUMBER = 40001,
        RC_CHARACTER_DELETE_WORLD_OFFLINE = 40002,
        RC_CHARACTER_DELETE_CLAN_LEADER = 40003,
        RC_CHARACTER_DELETE_MAIL_POINTS = 40004,
        RC_CHARACTER_DELETE_MARKETPLACE_POINTS = 40005,
        RC_CHARACTER_INFO_INVALID_SLOT_NUMBER = 50001,
        RC_CHARACTER_INFO_WORLD_OFFLINE = 50002,
        RC_WORLD_ENTER_INVALID_SLOT_NUMBER = 60001,
        RC_WORLD_ENTER_WORLD_OFFLINE = 60002,
        RC_WORLD_ENTER_QUEUE_CANCEL = 60003,
        RC_WORLD_ENTER_LOCKED = 60004,
        RC_WORLD_ENTER_CHARACTER_NOT_EXIST = 60005,
        RC_WORLD_ENTER_CHARACTER_DUPLICATED = 60006,
        RC_WORLD_ENTER_ACCOUNT_TYPE_BLOCKED = 60007,
        RC_WORLD_ENTER_NEED_NAME_CHANGE = 60008,
        RC_WORLD_ENTER_ACCOUNT_OFFLINE = 60009,
        RC_WORLD_ENTER_QUEUE_DUPLICATED = 60010,
        RC_CHARACTER_NAME_CHANGE_INVALID_SLOT_NUMBER = 61002,
        RC_CHARACTER_NAME_CHANGE_WORLD_OFFLINE = 61003,
        RC_CHARACTER_NAME_CHANGE_INVALID_CHARACTER = 61004,
        RC_CHARACTER_NAME_CHANGE_NAME_IN_USE = 61005,
        RC_CHARACTER_NAME_CHANGE_SAME_NAME = 61006,
        RC_CHARACTER_NAME_CHANGE_BAD_NAME = 61007,
        RC_CHARACTER_NAME_CHANGE_NAME_NOT_CHECKED = 61008,
        RC_DISTRICT_RESERVE_DISTRICT_OFFLINE = 70001,
        RC_DISTRICT_RESERVE_FACTION = 70002,
        RC_DISTRICT_RESERVE_ALREADY_IN_INSTANCE = 70003,
        RC_DISTRICT_RESERVE_ALREADY_IN_DISTRICT = 70004,
        RC_DISTRICT_RESERVE_INVALID_DISTRICT = 70005,
        RC_DISTRICT_RESERVE_FULL = 70006,
        RC_DISTRICT_RESERVE_NO_INSTANCES = 70007,
        RC_DISTRICT_RESERVE_FREEZE = 70008,
        RC_DISTRICT_RESERVE_NO_SUBSCRIPTION = 70009,
        RC_DISTRICT_RESERVE_CHARACTER_NOT_FOUND = 70010,
        RC_DISTRICT_RESERVE_ALREADY_QUEUED_FOR_INSTANCE = 70011,
        RC_DISTRICT_RESERVE_ALREADY_QUEUED_FOR_DISTRICT = 70012,
        RC_DISTRICT_RESERVE_NO_GROUP = 70013,
        RC_DISTRICT_RESERVE_NOT_LEADER = 70014,
        RC_DISTRICT_RESERVE_RATING = 70015,
        RC_DISTRICT_RESERVE_LOCKED = 70016,
        RC_DISTRICT_ENTER_NOT_RESERVED = 80001,
        RC_DISTRICT_ENTER_SUBSCRIPTION_EXPIRED = 80002,
        RC_DISTRICT_ATTACH_INVALID_DISTRICT_UID = 90001,
        RC_DISTRICT_ATTACH_ALREADY_ATTACHED = 90002,
        RC_CHAT_WHISPER_NOT_FOUND = 100001,
        RC_CHAT_WHISPER_IGNORED = 100002,
        RC_CHAT_WHISPER_GM = 100003,
        RC_GROUP_INVITE_DECLINED = 110001,
        RC_GROUP_INVITE_NOT_FOUND = 110002,
        RC_GROUP_INVITE_FACTION = 110003,
        RC_GROUP_INVITE_NOT_LEADER = 110004,
        RC_GROUP_INVITE_GROUP = 110005,
        RC_GROUP_INVITE_INVITE_TO = 110006,
        RC_GROUP_INVITE_FULL = 110007,
        RC_GROUP_INVITE_SELF = 110008,
        RC_GROUP_INVITE_IGNORED = 110009,
        RC_GROUP_INVITE_BOUNCED = 110010,
        RC_GROUP_INVITE_GM = 110012,
        RC_GROUP_INVITE_TUTORIAL_FROM = 110013,
        RC_GROUP_INVITE_TUTORIAL_TO = 110014,
        RC_GROUP_LEAVE_NO_GROUP = 120001,
        RC_GROUP_REMOVE_NO_GROUP = 130001,
        RC_GROUP_REMOVE_NOT_LEADER = 130002,
        RC_GROUP_REMOVE_SELF = 130003,
        RC_GROUP_REMOVE_NOT_FOUND = 130004,
        RC_GROUP_LEADER_NO_GROUP = 140001,
        RC_GROUP_LEADER_NOT_LEADER = 140002,
        RC_GROUP_LEADER_SELF = 140003,
        RC_GROUP_LEADER_NOT_FOUND = 140004,
        RC_GROUP_LEADER_OFFLINE = 140005,
        RC_GROUP_STATE_NO_GROUP = 150001,
        RC_CLAN_CREATE_NAME_IN_USE = 160001,
        RC_CLAN_CREATE_BAD_NAME = 160002,
        RC_CLAN_CREATE_INVALID_NAME = 160004,
        RC_CLAN_CREATE_CLAN = 160005,
        RC_CLAN_INVITE_DECLINED = 170001,
        RC_CLAN_INVITE_NOT_FOUND = 170002,
        RC_CLAN_INVITE_FACTION = 170003,
        RC_CLAN_INVITE_PERMISSION = 170004,
        RC_CLAN_INVITE_CLAN = 170005,
        RC_CLAN_INVITE_INVITE_TO = 170006,
        RC_CLAN_INVITE_FULL = 170007,
        RC_CLAN_INVITE_SELF = 170008,
        RC_CLAN_INVITE_NO_CLAN = 170009,
        RC_CLAN_INVITE_NO_DEFAULT_RANKS = 170010,
        RC_CLAN_INVITE_IGNORED = 170011,
        RC_CLAN_INVITE_CLAN_DELETED = 170012,
        RC_CLAN_INVITE_GM = 170013,
        RC_CLAN_LEAVE_NO_CLAN = 180001,
        RC_CLAN_LEAVE_LEADER = 180002,
        RC_CLAN_LEAVE_NO_CLAN_MEMBER = 180003,
        RC_CLAN_REMOVE_NO_CLAN = 190001,
        RC_CLAN_REMOVE_SELF = 190002,
        RC_CLAN_REMOVE_PERMISSION = 190003,
        RC_CLAN_REMOVE_NOT_FOUND = 190004,
        RC_CLAN_REMOVE_RANK = 190005,
        RC_CLAN_LEADER_NO_CLAN = 200001,
        RC_CLAN_LEADER_NOT_LEADER = 200002,
        RC_CLAN_LEADER_SELF = 200003,
        RC_CLAN_LEADER_NOT_FOUND = 200004,
        RC_CLAN_LEADER_RANK_NOT_FOUND = 200005,
        RC_CLAN_LEADER_OLD_LEADER_NOT_FOUND = 200006,
        RC_CLAN_LEADER_GENERAL_MEMBER_RANK_NOT_FOUND = 200007,
        RC_CLAN_BIO_NO_CLAN = 210001,
        RC_CLAN_BIO_EDIT_NO_PERMISSION = 220001,
        RC_CLAN_BIO_EDIT_NO_CLAN = 220002,
        RC_CLAN_SYMBOL_NO_CLAN = 230001,
        RC_CLAN_SYMBOL_EDIT_NO_PERMISSION = 240001,
        RC_CLAN_SYMBOL_EDIT_NO_CLAN = 240002,
        RC_GROUP_CONFIG_NO_GROUP = 250001,
        RC_GROUP_CONFIG_NOT_LEADER = 250002,
        RC_GROUP_JOIN_GROUP = 260001,
        RC_GROUP_JOIN_INVITE_FROM = 260002,
        RC_GROUP_JOIN_NOT_FOUND = 260003,
        RC_GROUP_JOIN_SELF = 260004,
        RC_GROUP_JOIN_NO_GROUP = 260005,
        RC_GROUP_JOIN_FULL = 260006,
        RC_GROUP_JOIN_FACTION = 260007,
        RC_GROUP_JOIN_PRIVATE = 260008,
        RC_GROUP_JOIN_IGNORE_LIST = 260009,
        RC_GROUP_JOIN_INVITE_TO = 260010,
        RC_GROUP_JOIN_TUTORIAL = 260011,
        RC_CLAN_THEME_NO_CLAN = 270001,
        RC_CLAN_THEME_EDIT_NO_PERMISSION = 280001,
        RC_CLAN_THEME_EDIT_NO_CLAN = 280002,
        RC_CLAN_MEMBER_STATS_NO_CLAN = 290001,
        RC_CLAN_STATS_NO_CLAN = 300001,
        RC_CLAN_STATS_NO_CLAN_MEMBER = 300002,
        RC_CLAN_MEMBER_PROFILE_NO_CLAN = 310001,
        RC_CLAN_MEMBER_PROFILE_NO_CLAN_MEMBER = 310002,
        RC_CLAN_MEMBER_BIO_EDIT_NO_CLAN = 320001,
        RC_CLAN_MEMBER_NOTE_EDIT_NO_PERMISSION = 330001,
        RC_CLAN_MEMBER_NOTE_EDIT_NO_CLAN = 330002,
        RC_CLAN_MEMBER_NOTE_EDIT_INVALID_NOTE_TYPE = 330003,
        RC_CLAN_MEMBER_NOTE_EDIT_NO_CLAN_MEMBER = 330004,
        RC_CLAN_RANK_CREATE_NOT_LEADER = 340001,
        RC_CLAN_RANK_CREATE_NO_CLAN = 340002,
        RC_CLAN_RANK_CREATE_INVALID_PERMISSION = 340003,
        RC_CLAN_RANK_CREATE_INVALID_RANK_NAME = 340004,
        RC_CLAN_RANK_CREATE_SLOT_FULL = 340005,
        RC_CLAN_RANK_CREATE_NAME_IN_USE = 340006,
        RC_CLAN_RANK_DELETE_NOT_LEADER = 350001,
        RC_CLAN_RANK_DELETE_NO_CLAN = 350002,
        RC_CLAN_RANK_DELETE_DEFAULT_RANK = 350003,
        RC_CLAN_RANK_DELETE_INVALID_RANKUID = 350004,
        RC_CLAN_RANK_DELETE_RANK_ASSIGNED = 350005,
        RC_CLAN_RANK_EDIT_NOT_LEADER = 360001,
        RC_CLAN_RANK_EDIT_NO_CLAN = 360002,
        RC_CLAN_RANK_EDIT_INVALID_PERMISSION = 360003,
        RC_CLAN_RANK_EDIT_INVALID_RANK_NAME = 360004,
        RC_CLAN_RANK_EDIT_INVALID_RANK_UID = 360005,
        RC_CLAN_RANK_EDIT_NAME_IN_USE = 360006,
        RC_CLAN_RANK_ASSIGN_NO_PERMISSION = 370001,
        RC_CLAN_RANK_ASSIGN_NO_CLAN = 370002,
        RC_CLAN_RANK_ASSIGN_NO_CLAN_MEMBER = 370003,
        RC_CLAN_RANK_ASSIGN_HIGHER_MEMBER = 370004,
        RC_CLAN_RANK_ASSIGN_HIGHER_RANK = 370005,
        RC_CLAN_RANK_ASSIGN_INVALID_RANKUID = 370006,
        RC_CLAN_INFORMATION_NO_CLAN = 380001,
        RC_CLAN_INFORMATION_EDIT_NO_PERMISSION = 390001,
        RC_CLAN_INFORMATION_EDIT_NO_CLAN = 390002,
        RC_CLAN_MOTD_EDIT_NO_PERMISSION = 400001,
        RC_CLAN_MOTD_EDIT_NO_CLAN = 400002,
        RC_CLAN_DELETE_NO_CLAN = 410001,
        RC_CLAN_DELETE_LEADER = 410002,
        RC_CLAN_MEMBER_STATE_NO_CLAN = 420001,
        RC_FRIENDLIST_ADD_SELF = 430002,
        RC_FRIENDLIST_ADD_ALREADY_ADDED = 430003,
        RC_FRIENDLIST_ADD_FULL = 430004,
        RC_FRIENDLIST_ADD_GM = 430005,
        RC_FRIENDLIST_ADD_SAME_ACCOUNT = 430006,
        RC_FRIENDLIST_ADD_INVALID_NAME = 430007,
        RC_FRIENDLIST_REMOVE_NO_FRIEND = 440001,
        RC_FRIENDLIST_STATE_NO_FRIEND = 450001,
        RC_IGNORELIST_ADD_NOT_FOUND = 460001,
        RC_IGNORELIST_ADD_SELF = 460002,
        RC_IGNORELIST_ADD_ALREADY_ADDED = 460003,
        RC_IGNORELIST_ADD_FULL = 460004,
        RC_IGNORELIST_ADD_GM = 460005,
        RC_IGNORELIST_ADD_SAME_ACCOUNT = 460006,
        RC_IGNORELIST_ADD_INVALID_NAME = 460007,
        RC_IGNORELIST_REMOVE_NO_IGNORE = 470001,
        RC_GM_COMMAND_PERMISSION = 480001,
        RC_GM_COMMAND_PENDING = 480002,
        RC_GM_COMMAND_CHARACTER_NOT_FOUND = 480003,
        RC_GM_COMMAND_CHARACTER_NO_DISTRICT = 480004,
        RC_BULKLOG_SESSION_ARCHIVE_EXECUTION_COUNT = 490001,
        RC_POINTS_NOT_ENOUGH = 500001,
        RC_INIT_SERVICE_BROKER_NOT_FOUND = 510001,
        RC_INIT_SERVICE_BROKER_DISABLED = 510002,
        RC_INIT_SERVICE_BROKER_CONVERSATION_GROUP_ID = 510003,
        RC_MARKETPLACE_THUMBNAIL_INVALID_PARAM = 520001,
        RC_GROUP_LIST_PAGE = 530001,
        RC_GROUP_LIST_NOT_FOUND = 530002,
        RC_GROUP_INFO_NOT_FOUND = 540001,
        RC_GROUP_INFO_FACTION = 540002,
        RC_GROUP_INFO_NO_GROUP = 540003,
        RC_GROUP_INFO_PRIVATE = 540004,
        RC_CHARACTERFINDER_INFO_NO_CHARACTER = 610001,
        RC_CHARACTERFINDER_INFO_GM = 610002,
        RC_MARKETPLACE_SELLER_LIST_INVALID_STRING = 62000,
        RC_MARKETPLACE_AUCTION_CREATE_INVALID_BUYOUT = 630001,
        RC_MARKETPLACE_AUCTION_CREATE_INVALID_BID = 630002,
        RC_MARKETPLACE_AUCTION_CREATE_AUCTION_LIMIT = 630004,
        RC_MARKETPLACE_AUCTION_CREATE_INVALID_TYPE = 630005,
        RC_MARKETPLACE_AUCTION_CREATE_INVALID_CASH = 630006,
        RC_MARKETPLACE_AUCTION_CREATE_NO_ITEM = 630007,
        RC_MARKETPLACE_AUCTION_CREATE_DUPE = 630008,
        RC_MARKETPLACE_AUCTION_CREATE_INVALID_DURATION = 630009,
        RC_MARKETPLACE_AUCTION_CREATE_INVALID_ITEM = 630010,
        RC_MARKETPLACE_AUCTION_CREATE_NO_CASH = 630011,
        RC_MARKETPLACE_AUCTION_CREATE_CASH_TYPE = 630012,
        RC_MARKETPLACE_AUCTION_CREATE_NOT_SELLABLE = 630013,
        RC_MARKETPLACE_AUCTION_CREATE_MINIMUM_CASH = 630014,
        RC_MARKETPLACE_AUCTION_BID_NO_AUCTION = 640001,
        RC_MARKETPLACE_AUCTION_BID_SELF = 640002,
        RC_MARKETPLACE_AUCTION_BID_EXPIRED = 640003,
        RC_MARKETPLACE_AUCTION_BID_BUYOUT_EXCEEDED = 640004,
        RC_MARKETPLACE_AUCTION_BID_MINIMUM = 640005,
        RC_MARKETPLACE_AUCTION_BID_CURRENT = 640006,
        RC_MARKETPLACE_AUCTION_BID_DUPE = 640007,
        RC_MARKETPLACE_AUCTION_BID_AMOUNT = 640008,
        RC_MARKETPLACE_AUCTION_BID_INVALID_AMOUNT = 640009,
        RC_MARKETPLACE_AUCTION_BID_INVALID_TYPE = 640010,
        RC_MARKETPLACE_AUCTION_BID_FACTION = 640011,
        RC_MARKETPLACE_AUCTION_CANCEL_NO_AUCTION = 650001,
        RC_MARKETPLACE_AUCTION_CANCEL_EXPIRED = 650002,
        RC_MARKETPLACE_AUCTION_CANNOT_CANCEL = 650003,
        RC_MARKETPLACE_AUCTION_ITEM_NO_AUCTION = 660001,
        RC_MARKETPLACE_AUCTION_ITEM_PERMISSION = 660002,
        RC_MARKETPLACE_AUCTION_LIST_INVALID_SORT = 670001,
        RC_MARKETPLACE_MYBID_LIST_INVALID_SORT = 680001,
        RC_MARKETPLACE_MYAUCTION_LIST_INVALID_SORT = 690001,
        RC_MAIL_LIST_INVALID_SORT = 700001,
        RC_MAIL_SEND_NOT_FOUND = 710001,
        RC_MAIL_SEND_SELF = 710002,
        RC_MAIL_SEND_BLOCKED = 710003,
        RC_MAIL_SEND_IGNORED = 710004,
        RC_MAIL_SEND_MAIL_LIMIT = 710005,
        RC_MAIL_SEND_ACCOUNT_MAIL_LIMIT = 710006,
        RC_MAIL_SEND_NO_ITEM = 710007,
        RC_MAIL_SEND_COST = 710008,
        RC_MAIL_SEND_INVALID_CASH = 710009,
        RC_MAIL_SEND_INVALID_ITEM = 710010,
        RC_MAIL_SEND_DUPE = 710011,
        RC_MAIL_SEND_NOT_SELLABLE = 710012,
        RC_MAIL_READ_NOT_FOUND = 720001,
        RC_MAIL_READ_NOT_OWNER = 720002,
        RC_MAIL_DELETE_NOT_FOUND = 730001,
        RC_MAIL_DELETE_NOT_OWNER = 730002,
        RC_MAIL_DETACH_NOT_FOUND = 740001,
        RC_MAIL_DETACH_NOT_OWNER = 740002,
        RC_MAIL_DETACH_NO_ATTACHED_CASH = 740003,
        RC_MAIL_DETACH_NO_ATTACHED_ITEM = 740004,
        RC_MAIL_DETACH_NO_ATTACHED_POINTS = 740005,
        RC_MAIL_DETACH_INVALID_TYPE = 740006,
        RC_MAIL_DETACH_INVALID_ITEM = 740007,
        RC_MAIL_DETACH_CASH_ERROR = 740008,
        RC_MAIL_DETACH_ITEM_ERROR = 740009,
        RC_MAIL_DETACH_POINTS_ERROR = 740010,
        RC_MAIL_DETACH_NO_ACCOUNT = 740011,
        RC_MAIL_ATTACH_NOT_FOUND = 750001,
        RC_MAIL_ATTACH_NOT_OWNER = 750002,
        RC_MAIL_ATTACH_ATTACHED_CASH = 750003,
        RC_MAIL_ATTACH_ATTACHED_ITEM = 750004,
        RC_MAIL_ATTACH_INVALID = 750005,
        RC_MAIL_ITEM_NOT_FOUND = 760001,
        RC_LEAGUE_NOT_FOUND = 770001,
        RC_LEAGUE_MYLEAGUE_CLAN_NOT_FOUND = 780001,
        RC_LEAGUE_VALUE_CLAN_NOT_FOUND = 790001,
        RC_LEAGUE_VALUE_INVALID_STATISTIC_ID = 790002,
        RC_LEAGUE_VALUE_INVALID_LEAGUE_TYPE = 790003,
        RC_LEAGUE_VALUE_INVALID_LEAGUE_CYCLE = 790004,
        RC_DATABASE_EVENT_END_DIALOG = 800001,
        RC_DATABASE_EVENT_CONVERSATION_ERROR = 800002,
        RC_DATABASE_EVENT_UNKNOWN_MESSAGE_TYPE = 800003,
        RC_DATABASE_EVENT_TIMEOUT = 800004,
        RC_CHARACTER_LOAD_SUCCESS_WITH_DUPLICATED_ONLINE = 810001,
        RC_CHARACTER_LOAD_DB_OUT_OF_SYNC = 810002,
        RC_CHARACTER_LOAD_SUCCESS_WITH_REDEMPTIONKEY_REWARD_FAILURE = 810003,
        RC_CONFIGFILE_LOAD_ALREADY_LOADED = 820001,
        RC_NAME_QUERY_NOT_FOUND = 830001,
        RC_DISTRICT_QUEUE_CANCEL_NO_GROUP = 840001,
        RC_DISTRICT_QUEUE_CANCEL_NOT_LEADER = 840002
    }
}