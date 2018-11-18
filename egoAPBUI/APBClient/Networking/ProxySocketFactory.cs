using System.Net;
using System.Net.Sockets;
using Org.Mentalis.Network.ProxySocket;

namespace APBClient.Networking
{
    public class ProxySocketFactory : ISocketFactory
    {
        private string ProxyIP, ProxyUsername, ProxyPassword;
        private int ProxyPort;

        public ProxySocketFactory(string proxyIP, int proxyPort, string proxyUsername, string proxyPassword)
        {
            ProxyIP = proxyIP;
            ProxyPort = proxyPort;
            ProxyUsername = proxyUsername;
            ProxyPassword = proxyPassword;
        }

        public ProxySocket CreateSocket()
        {
            var socket = new ProxySocket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            socket.ProxyEndPoint = new IPEndPoint(IPAddress.Parse(ProxyIP), ProxyPort);
            socket.ProxyType = ProxyTypes.Socks5;
            if (ProxyUsername != null && ProxyPassword != null)
            {
                socket.ProxyUser = ProxyUsername;
                socket.ProxyPass = ProxyPassword;
            }
            return socket;
        }
    }
}