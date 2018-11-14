/*
    Copyright © 2002, The KPD-Team
    All rights reserved.
    http://www.mentalis.org/
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
    - Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer. 
    - Neither the name of the KPD-Team, nor the names of its contributors
       may be used to endorse or promote products derived from this
       software without specific prior written permission. 
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
  THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  OF THE POSSIBILITY OF SUCH DAMAGE.
*/

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