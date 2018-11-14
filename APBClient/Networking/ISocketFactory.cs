using Org.Mentalis.Network.ProxySocket;

namespace APBClient.Networking
{
    public interface ISocketFactory
    {
        ProxySocket CreateSocket();
    }
}