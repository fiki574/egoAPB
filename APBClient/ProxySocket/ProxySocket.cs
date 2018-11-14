using System;
using System.Net;
using System.Net.Sockets;

namespace Org.Mentalis.Network.ProxySocket
{
	public enum ProxyTypes
    {
		None,
		Socks4,
		Socks5
	}

    public class ProxySocket : Socket
    {
		public ProxySocket (AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType) : this(addressFamily, socketType, protocolType, "") {}
		public ProxySocket (AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType, string proxyUsername) : this(addressFamily, socketType, protocolType, proxyUsername, "") {}
		public ProxySocket (AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType, string proxyUsername, string proxyPassword) : base(addressFamily, socketType, protocolType)
        {
			ProxyUser = proxyUsername;
			ProxyPass = proxyPassword;
			ToThrow = new InvalidOperationException();
		}

		public new void Connect(EndPoint remoteEP)
        {
			if (remoteEP == null)
				throw new ArgumentNullException("<remoteEP> cannot be null.");

			if (ProtocolType != ProtocolType.Tcp || ProxyType == ProxyTypes.None || ProxyEndPoint == null)
				base.Connect(remoteEP);
			else
            {
				base.Connect(ProxyEndPoint);
				if (ProxyType == ProxyTypes.Socks4)
					new Socks4Handler(this, ProxyUser).Negotiate((IPEndPoint)remoteEP);
				else if (ProxyType == ProxyTypes.Socks5)
					new Socks5Handler(this, ProxyUser, ProxyPass).Negotiate((IPEndPoint)remoteEP);
			}
		}
		
		public new void Connect(string host, int port)
        {
			if (host == null)
				throw new ArgumentNullException("<host> cannot be null.");

			if (port <= 0 || port > 65535)
				throw new ArgumentException("Invalid port.");

			if (ProtocolType != ProtocolType.Tcp || ProxyType == ProxyTypes.None || ProxyEndPoint == null)
				base.Connect(new IPEndPoint(Dns.Resolve(host).AddressList[0], port));
			else
            {
				base.Connect(ProxyEndPoint);
				if (ProxyType == ProxyTypes.Socks4)
					new Socks4Handler(this, ProxyUser).Negotiate(host, port);
				else if (ProxyType == ProxyTypes.Socks5)
					new Socks5Handler(this, ProxyUser, ProxyPass).Negotiate(host, port);
			}
		}

		public new IAsyncResult BeginConnect(EndPoint remoteEP, AsyncCallback callback, object state)
        {
			if (remoteEP == null || callback == null)
				throw new ArgumentNullException();

			if (ProtocolType != ProtocolType.Tcp || ProxyType == ProxyTypes.None || ProxyEndPoint == null) 
				return base.BeginConnect(remoteEP, callback, state);
			else
            {
				CallBack = callback;
				if (ProxyType == ProxyTypes.Socks4)
                {
					AsyncResult = new Socks4Handler(this, ProxyUser).BeginNegotiate((IPEndPoint)remoteEP, new HandShakeComplete(OnHandShakeComplete), ProxyEndPoint);
					return AsyncResult;
				}
                else if(ProxyType == ProxyTypes.Socks5)
                {
					AsyncResult = new Socks5Handler(this, ProxyUser, ProxyPass).BeginNegotiate((IPEndPoint)remoteEP, new HandShakeComplete(OnHandShakeComplete), ProxyEndPoint);
					return AsyncResult;
				}
				return null;
			}
		}
		
		public new IAsyncResult BeginConnect(string host, int port, AsyncCallback callback, object state)
        {
			if (host == null || callback == null)
				throw new ArgumentNullException();

			if (port <= 0 || port >  65535)
				throw new ArgumentException();

			CallBack = callback;
			if (ProtocolType != ProtocolType.Tcp || ProxyType == ProxyTypes.None || ProxyEndPoint == null)
            {
				RemotePort = port;
				AsyncResult = BeginDns(host, new HandShakeComplete(OnHandShakeComplete));
				return AsyncResult;
			}
            else
            {
				if (ProxyType == ProxyTypes.Socks4)
                {
					AsyncResult = new Socks4Handler(this, ProxyUser).BeginNegotiate(host, port, new HandShakeComplete(OnHandShakeComplete), ProxyEndPoint);
					return AsyncResult;
				}
                else if(ProxyType == ProxyTypes.Socks5)
                {
					AsyncResult = new Socks5Handler(this, ProxyUser, ProxyPass).BeginNegotiate(host, port, new HandShakeComplete(OnHandShakeComplete), ProxyEndPoint);
					return AsyncResult;
				}
				return null;
			}
		}
		
		public new void EndConnect(IAsyncResult asyncResult)
        {
			if (asyncResult == null)
				throw new ArgumentNullException();

			if (!asyncResult.IsCompleted)
				throw new ArgumentException();

			if (ToThrow != null)
				throw ToThrow;

			return;
		}
		
		internal IAsyncProxyResult BeginDns(string host, HandShakeComplete callback)
        {
			try
            {
				Dns.BeginResolve(host, new AsyncCallback(OnResolved), this);
				return new IAsyncProxyResult();
			}
            catch
            {
				throw new SocketException();
			}
		}
		
		private void OnResolved(IAsyncResult asyncResult)
        {
			try
            {
				IPHostEntry dns = Dns.EndResolve(asyncResult);
				base.BeginConnect(new IPEndPoint(dns.AddressList[0], RemotePort), new AsyncCallback(OnConnect), State);
			}
            catch (Exception e)
            {
				OnHandShakeComplete(e);
			}
		}

		private void OnConnect(IAsyncResult asyncResult)
        {
			try
            {
				base.EndConnect(asyncResult);
				OnHandShakeComplete(null);
			}
            catch (Exception e)
            {
				OnHandShakeComplete(e);
			}
		}
	
		private void OnHandShakeComplete(Exception error)
        {
			if (error != null)
				Close();

			ToThrow = error;
			AsyncResult.Reset();
            CallBack?.Invoke(AsyncResult);
        }
		
		public IPEndPoint ProxyEndPoint
        {
			get
            {
				return m_ProxyEndPoint;
			}
			set
            {
				m_ProxyEndPoint = value;
			}
		}

		public ProxyTypes ProxyType
        {
			get
            {
				return m_ProxyType;
			}
			set
            {
				m_ProxyType = value;
			}
		}

		private object State
        {
			get
            {
				return m_State;
			}
			set
            {
				m_State = value;
			}
		}
		
		public string ProxyUser
        {
			get
            {
				return m_ProxyUser;
			}
			set
            {
                m_ProxyUser = value ?? throw new ArgumentNullException();
			}
		}
		
		public string ProxyPass
        {
			get
            {
				return m_ProxyPass;
			}
			set
            {
                m_ProxyPass = value ?? throw new ArgumentNullException();
			}
		}
		
		private IAsyncProxyResult AsyncResult
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
		
		private Exception ToThrow
        {
			get
            {
				return m_ToThrow;
			}
			set
            {
				m_ToThrow = value;
			}
		}
		
		private int RemotePort
        {
			get
            {
				return m_RemotePort;
			}
			set
            {
				m_RemotePort = value;
			}
		}
		
		private object m_State;
		private IPEndPoint m_ProxyEndPoint = null;
		private ProxyTypes m_ProxyType = ProxyTypes.None;
		private string m_ProxyUser = null;
		private string m_ProxyPass = null;
		private AsyncCallback CallBack = null;
		private IAsyncProxyResult m_AsyncResult;
		private Exception m_ToThrow = null;
		private int m_RemotePort;
	}
}