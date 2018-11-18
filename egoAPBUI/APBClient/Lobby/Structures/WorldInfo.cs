using System.Net;

namespace APBClient.Lobby
{
    public class WorldInfo
    {
        public int Uid;
        public string Name;
        public StatusType Status;
        public int Population;
        public int EnfFaction;
        public int CrimFaction;
        public int PremiumOnly;
        public string Region;
        public IPAddress PingIp;
    }
}