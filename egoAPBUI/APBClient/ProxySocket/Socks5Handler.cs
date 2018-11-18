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
using System.Text;
using Org.Mentalis.Network.ProxySocket.Authentication;
#pragma warning disable 0618

namespace Org.Mentalis.Network.ProxySocket
{
	internal sealed class Socks5Handler : SocksHandler
    {
		public Socks5Handler(Socket server) : this(server, "") {}
		public Socks5Handler(Socket server, string user) : this(server, user, "") {}
		public Socks5Handler(Socket server, string user, string pass) : base(server, user)
        {
			Password = pass;
		}
		
		private void Authenticate()
        {
			Server.Send(new byte [] {5, 2, 0, 2});
			byte[] buffer = ReadBytes(2);
			if (buffer[1] == 255)
				throw new ProxyException("No authentication method accepted.");

			AuthMethod authenticate;
			switch (buffer[1])
            {
				case 0:
					authenticate = new AuthNone(Server);
					break;
				case 2:
					authenticate = new AuthUserPass(Server, Username, Password);
					break;
				default:
					throw new ProtocolViolationException();
			}
			authenticate.Authenticate();
		}
		
		private byte[] GetHostPortBytes(string host, int port) {
			if (host == null)
				throw new ArgumentNullException();

			if (port <= 0 || port > 65535 || host.Length > 255)
				throw new ArgumentException();

			byte [] connect = new byte[7 + host.Length];
			connect[0] = 5;
			connect[1] = 1;
			connect[2] = 0;
			connect[3] = 3;
			connect[4] = (byte)host.Length;
			Array.Copy(Encoding.ASCII.GetBytes(host), 0, connect, 5, host.Length);
			Array.Copy(PortToBytes(port), 0, connect, host.Length + 5, 2);
			return connect;
		}
		
		private byte[] GetEndPointBytes(IPEndPoint remoteEP)
        {
			if (remoteEP == null)
				throw new ArgumentNullException();

			byte [] connect = new byte[10];
			connect[0] = 5;
			connect[1] = 1;
			connect[2] = 0;
			connect[3] = 1;
			Array.Copy(AddressToBytes(remoteEP.Address.Address), 0, connect, 4, 4);
			Array.Copy(PortToBytes(remoteEP.Port), 0, connect, 8, 2);
			return connect;
		}

		public override void Negotiate(string host, int port)
        {
			Negotiate(GetHostPortBytes(host, port));
		}
		
		public override void Negotiate(IPEndPoint remoteEP)
        {
			Negotiate(GetEndPointBytes(remoteEP));
		}
		
		private void Negotiate(byte[] connect)
        {
			Authenticate();
			Server.Send(connect);
			byte[] buffer = ReadBytes(4);
			if (buffer[1] != 0)
            {
				Server.Close();
				throw new ProxyException(buffer[1]);
			}

			switch(buffer[3])
            {
				case 1:
					buffer = ReadBytes(6);
					break;
				case 3:
					buffer = ReadBytes(1);
					buffer = ReadBytes(buffer[0] + 2);
					break;
				case 4:
					buffer = ReadBytes(18);
					break;
				default:
					Server.Close();
					throw new ProtocolViolationException();
			}
		}

		public override IAsyncProxyResult BeginNegotiate(string host, int port, HandShakeComplete callback, IPEndPoint proxyEndPoint)
        {
			ProtocolComplete = callback;
			HandShake = GetHostPortBytes(host, port);
			Server.BeginConnect(proxyEndPoint, new AsyncCallback(this.OnConnect), Server);
			AsyncResult = new IAsyncProxyResult();
			return AsyncResult;
		}
		
		public override IAsyncProxyResult BeginNegotiate(IPEndPoint remoteEP, HandShakeComplete callback, IPEndPoint proxyEndPoint)
        {
			ProtocolComplete = callback;
			HandShake = GetEndPointBytes(remoteEP);
			Server.BeginConnect(proxyEndPoint, new AsyncCallback(this.OnConnect), Server);
			AsyncResult = new IAsyncProxyResult();
			return AsyncResult;
		}
		
		private void OnConnect(IAsyncResult ar)
        {
			try
            {
				Server.EndConnect(ar);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
				return;
			}

			try
            {
				Server.BeginSend(new byte [] {5, 2, 0, 2}, 0, 4, SocketFlags.None, new AsyncCallback(OnAuthSent), Server);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
			}
		}
		
		private void OnAuthSent(IAsyncResult ar) {
			try
            {
				Server.EndSend(ar);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
				return;
			}

			try
            {
				Buffer = new byte[1024];
				Received = 0;
				Server.BeginReceive(Buffer, 0, Buffer.Length, SocketFlags.None, new AsyncCallback(OnAuthReceive), Server);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
			}
		}

		private void OnAuthReceive(IAsyncResult ar)
        {
			try
            {
				Received += Server.EndReceive(ar);
				if (Received <= 0)
					throw new SocketException();
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
				return;
			}

			try
            {
				if (Received < 2) 
					Server.BeginReceive(Buffer, Received, Buffer.Length - Received, SocketFlags.None, new AsyncCallback(OnAuthReceive), Server);
				else
                { 
					AuthMethod authenticate;
					switch(Buffer[1])
                    {
						case 0:
							authenticate = new AuthNone(Server);
							break;
						case 2:
							authenticate = new AuthUserPass(Server, Username, Password);
							break;
						default:
							ProtocolComplete(new SocketException());
							return;
					}
					authenticate.BeginAuthenticate(new HandShakeComplete(OnAuthenticated));
				}
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
			}
		}
		
		private void OnAuthenticated(Exception e)
        {
			if (e != null)
            {
				ProtocolComplete(e);
				return;
			}

			try
            {
				Server.BeginSend(HandShake, 0, HandShake.Length, SocketFlags.None, new AsyncCallback(OnSent), Server);
			}
            catch (Exception ex)
            {
				ProtocolComplete(ex);
			}
		}
		
		private void OnSent(IAsyncResult ar)
        {
			try
            {
				Server.EndSend(ar);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
				return;
			}

			try
            {
				Buffer = new byte[5];
				Received = 0;
				Server.BeginReceive(Buffer, 0, Buffer.Length, SocketFlags.None, new AsyncCallback(OnReceive), Server);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
			}
		}
		
		private void OnReceive(IAsyncResult ar)
        {
			try
            {
				Received += Server.EndReceive(ar);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
				return;
			}

			try
            {
				if (Received == Buffer.Length)
					ProcessReply(Buffer);
				else
					Server.BeginReceive(Buffer, Received, Buffer.Length - Received, SocketFlags.None, new AsyncCallback(OnReceive), Server);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
			}
		}
		
		private void ProcessReply(byte[] buffer)
        {
			switch(buffer[3])
            {
				case 1:
					Buffer = new byte[5]; 
					break;
				case 3:
					Buffer = new byte[buffer[4] + 2];
					break;
				case 4:
					buffer = new byte[17];
					break;
				default:
					throw new ProtocolViolationException();
			}
			Received = 0;
			Server.BeginReceive(Buffer, 0, Buffer.Length, SocketFlags.None, new AsyncCallback(OnReadLast), Server);
		}
		
		private void OnReadLast(IAsyncResult ar)
        {
			try
            {
				Received += Server.EndReceive(ar);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
				return;
			}

			try
            {
				if (Received == Buffer.Length)
					ProtocolComplete(null);
				else
					Server.BeginReceive(Buffer, Received, Buffer.Length - Received, SocketFlags.None, new AsyncCallback(OnReadLast), Server);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
			}
		}
		
		private string Password
        {
			get
            {
				return m_Password;
			}
			set
            {
                m_Password = value ?? throw new ArgumentNullException();
			}
		}
		
		private byte[] HandShake
        {
			get
            {
				return m_HandShake;
			}
			set
            {
				m_HandShake = value;
			}
		}

		private string m_Password;
		private byte[] m_HandShake;
	}
}