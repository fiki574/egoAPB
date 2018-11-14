using System;
using System.Net;
using System.Net.Sockets;

namespace Org.Mentalis.Network.ProxySocket
{
	internal delegate void HandShakeComplete(Exception error);
	
	internal abstract class SocksHandler
    {
		public SocksHandler(Socket server, string user)
        {
			Server = server;
			Username = user;
		}

		protected byte[] PortToBytes(int port)
        {
			byte [] ret = new byte[2];
			ret[0] = (byte)(port / 256);
			ret[1] = (byte)(port % 256);
			return ret;
		}
		
		protected byte[] AddressToBytes(long address)
        {
			byte [] ret = new byte[4];
			ret[0] = (byte)(address % 256);
			ret[1] = (byte)((address / 256) % 256);
			ret[2] = (byte)((address / 65536) % 256);
			ret[3] = (byte)(address / 16777216);
			return ret;
		}
		
		protected byte[] ReadBytes(int count)
        {
			if (count <= 0)
				throw new ArgumentException();

			byte[] buffer = new byte[count];
			int received = 0;
			while(received != count)
				received += Server.Receive(buffer, received, count - received, SocketFlags.None);

			return buffer;
		}
		
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

		protected string Username
        {
			get
            {
				return m_Username;
			}
			set
            {
                m_Username = value ?? throw new ArgumentNullException();
			}
		}

        protected IAsyncProxyResult AsyncResult
        {
			get
            {
				return m_AsyncResult;
			}
			set
            {
				m_AsyncResult = value;
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
		
		private Socket m_Server;
		private string m_Username;
		private IAsyncProxyResult m_AsyncResult;
		private byte[] m_Buffer;
		private int m_Received;
		protected HandShakeComplete ProtocolComplete;
		public abstract void Negotiate(string host, int port);
		public abstract void Negotiate(IPEndPoint remoteEP);
		public abstract IAsyncProxyResult BeginNegotiate(IPEndPoint remoteEP, HandShakeComplete callback, IPEndPoint proxyEndPoint);
		public abstract IAsyncProxyResult BeginNegotiate(string host, int port, HandShakeComplete callback, IPEndPoint proxyEndPoint);
	}
}