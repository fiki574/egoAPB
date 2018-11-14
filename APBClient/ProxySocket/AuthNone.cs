using System.Net.Sockets;

namespace Org.Mentalis.Network.ProxySocket.Authentication
{
	internal sealed class AuthNone : AuthMethod
    {
		public AuthNone(Socket server) : base(server) {}
		public override void Authenticate()
        {
			return;
		}

		public override void BeginAuthenticate(HandShakeComplete callback)
        {
			callback(null);
		}
	}
}