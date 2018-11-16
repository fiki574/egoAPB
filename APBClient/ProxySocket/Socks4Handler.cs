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
#pragma warning disable 0618

namespace Org.Mentalis.Network.ProxySocket
{
	internal sealed class Socks4Handler : SocksHandler
    {
		public Socks4Handler(Socket server, string user) : base(server, user) {}
		
		private byte[] GetHostPortBytes(string host, int port)
        {
			if (host == null)
				throw new ArgumentNullException();

			if (port <= 0 || port > 65535)
				throw new ArgumentException();

			byte [] connect = new byte[10 + Username.Length + host.Length];
			connect[0] = 4;
			connect[1] = 1;
			Array.Copy(PortToBytes(port), 0, connect, 2, 2);
			connect[4] = connect[5] = connect[6] = 0;
			connect[7] = 1;
			Array.Copy(Encoding.ASCII.GetBytes(Username), 0, connect, 8, Username.Length);
			connect[8 + Username.Length] = 0;
			Array.Copy(Encoding.ASCII.GetBytes(host), 0, connect, 9 + Username.Length, host.Length);
			connect[9 + Username.Length + host.Length] = 0;
			return connect;
		}
		
		private byte[] GetEndPointBytes(IPEndPoint remoteEP)
        {
			if (remoteEP == null)
				throw new ArgumentNullException();

			byte [] connect = new byte[9 + Username.Length];
			connect[0] = 4;
			connect[1] = 1;
			Array.Copy(PortToBytes(remoteEP.Port), 0, connect, 2, 2);
            Array.Copy(AddressToBytes(remoteEP.Address.Address), 0, connect, 4, 4);
			Array.Copy(Encoding.ASCII.GetBytes(Username), 0, connect, 8, Username.Length);
			connect[8 + Username.Length] = 0;
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
		
		private void Negotiate(byte [] connect)
        {
			if (connect == null)
				throw new ArgumentNullException();

			if (connect.Length < 2)
				throw new ArgumentException();

			Server.Send(connect);
			byte [] buffer = ReadBytes(8);
			if (buffer[1] != 90)
            {
				Server.Close();
				throw new ProxyException("Negotiation failed.");	
			}
		}
		
		public override IAsyncProxyResult BeginNegotiate(string host, int port, HandShakeComplete callback, IPEndPoint proxyEndPoint)
        {
			ProtocolComplete = callback;
			Buffer = GetHostPortBytes(host, port);
			Server.BeginConnect(proxyEndPoint, new AsyncCallback(OnConnect), Server);
			AsyncResult = new IAsyncProxyResult();
			return AsyncResult;
		}
		
		public override IAsyncProxyResult BeginNegotiate(IPEndPoint remoteEP, HandShakeComplete callback, IPEndPoint proxyEndPoint)
        {
			ProtocolComplete = callback;
			Buffer = GetEndPointBytes(remoteEP);
			Server.BeginConnect(proxyEndPoint, new AsyncCallback(OnConnect), Server);
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
				Server.BeginSend(Buffer, 0, Buffer.Length, SocketFlags.None, new AsyncCallback(OnSent), Server);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
			}
		}
		
		private void OnSent(IAsyncResult ar)
        {
			try
            {
				if (Server.EndSend(ar) < Buffer.Length)
                {
					ProtocolComplete(new SocketException());
					return;
				}
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
				return;
			}

			try
            {
				Buffer = new byte[8];
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
				int received = Server.EndReceive(ar);
				if (received <= 0)
                {
					ProtocolComplete(new SocketException());
					return;
				}

				Received += received;
				if (Received == 8)
                {
					if (Buffer[1] == 90)
						ProtocolComplete(null);
					else
                    {
						Server.Close();
						ProtocolComplete(new ProxyException("Negotiation failed."));
					}
				}
                else
					Server.BeginReceive(Buffer, Received, Buffer.Length - Received, SocketFlags.None, new AsyncCallback(OnReceive), Server);
			}
            catch (Exception e)
            {
				ProtocolComplete(e);
			}
		}
	}
}