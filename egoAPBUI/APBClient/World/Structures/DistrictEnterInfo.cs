using System.Net;

namespace APBClient.World
{
    public class DistrictEnterInfo
    {
        public int ReturnCode;
        public IPAddress DistrictServerIpAddress;
        public ushort DistrictServerPort;
        public ulong Timestamp;
        public byte[] HandshakeHash;
        public byte[] XXTEAKey;
    }
}