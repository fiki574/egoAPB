using System.Net.Sockets;
using Org.Mentalis.Network.ProxySocket;

namespace APBClient.Networking
{
    public class StandardSocketFactory : ISocketFactory
    {
        public ProxySocket CreateSocket()
        {
            return new ProxySocket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        }
    }
}