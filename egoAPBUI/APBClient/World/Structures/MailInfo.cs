using System;

namespace APBClient.World
{
    public class MailInfo
    {
        public byte Type;
        public int Total;
        public int Unread;
        public int Expired;
        public Mail[] Mails;

        public class Mail
        {
            /*
            16:30:06 - hosting: Send [GC2WS_ASK_MAIL_LIST]
            16:30:06 - hosting: m_nPage 1
            16:30:06 - hosting: m_nSortType 4
            
            16:30:06 - hosting: Receive [WS2GC_ANS_MAIL_LIST]
            16:30:06 - hosting: m_nReturnCode 0
            16:30:06 - hosting: m_nTotalRows 20
            16:30:06 - hosting: m_nMails 10
            16:30:06 - hosting: m_nUnreadMailCount 0
            ...
            */
            public int ID;
            public int SenderID;
            public string SenderName;
            public string Subject;
            public int ItemType;
            public int Cash;
            public DateTime SendTime;
            public int RemainingTime;
            public bool Read;
            public bool FromGM;
            public bool Returned;
        }
    }
}