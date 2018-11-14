using System.Net;

namespace APBClient.Lobby
{
    public class WorldEnterData
    {
        public int ReturnCode;
        public IPAddress WorldServerIpAddress;
        public ushort WorldServerPort;
        public ulong Timestamp;
        public IPAddress PingServerIpAddress;
        public string Region;
    }
}