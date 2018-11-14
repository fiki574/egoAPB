using System;
using System.Net.Sockets;

namespace Org.Mentalis.Network.ProxySocket.Authentication
{
	internal abstract class AuthMethod
    {
		public AuthMethod(Socket server)
        {
			Server = server;
		}

		public abstract void Authenticate();
		public abstract void BeginAuthenticate(HandShakeComplete callback);
		protected Socket Server
        {
			get
            {
				return m_Server;
			}
			set
            {
                m_Server = value ?? throw new ArgumentNullException();
			}
		}
		
		protected byte[] Buffer
        {
			get
            {
				return m_Buffer;
			}
			set
            {
				m_Buffer = value;
			}
		}

		protected int Received
        {
			get
            {
				return m_Received;
			}
			set
            {
				m_Received = value;
			}
		}

		private byte[] m_Buffer;
		private Socket m_Server;
		protected HandShakeComplete CallBack;
		private int m_Received;
	}
}