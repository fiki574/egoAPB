using System;
using System.Net.Sockets;
using System.Text;

namespace Org.Mentalis.Network.ProxySocket.Authentication
{
	internal sealed class AuthUserPass : AuthMethod
    {
		public AuthUserPass(Socket server, string user, string pass) : base(server)
        {
			Username = user;
			Password = pass;
		}

        private byte[] GetAuthenticationBytes()
        {
			byte[] buffer = new byte[3 + Username.Length + Password.Length];
			buffer[0] = 1;
			buffer[1] = (byte)Username.Length;
			Array.Copy(Encoding.ASCII.GetBytes(Username), 0, buffer, 2, Username.Length);
			buffer[Username.Length + 2] = (byte)Password.Length;
			Array.Copy(Encoding.ASCII.GetBytes(Password), 0, buffer, Username.Length + 3, Password.Length);
			return buffer;
		}

		public override void Authenticate()
        {
			Server.Send(GetAuthenticationBytes());
			byte[] buffer = new byte[2];
			int received = 0;
			while (received != 2)
				received += Server.Receive(buffer, received, 2 - received, SocketFlags.None);

            if (buffer[1] != 0)
            {
				Server.Close();
				throw new ProxyException("Username/password combination rejected.");
			}
			return;
		}
		
		public override void BeginAuthenticate(HandShakeComplete callback)
        {
			CallBack = callback;
			Server.BeginSend(GetAuthenticationBytes(), 0, 3 + Username.Length + Password.Length, SocketFlags.None, new AsyncCallback(OnSent), Server);
			return;
		}

        private void OnSent(IAsyncResult ar)
        {
			try
            {
				Server.EndSend(ar);
				Buffer = new byte[2];
				Server.BeginReceive(Buffer, 0, 2, SocketFlags.None, new AsyncCallback(OnReceive), Server);
			}
            catch (Exception e)
            {
				CallBack(e);
			}
		}

        private void OnReceive(IAsyncResult ar)
        {
			try
            {
				Received += Server.EndReceive(ar);
				if (Received == Buffer.Length)
					if (Buffer[1] == 0)
						CallBack(null);
					else
						throw new ProxyException("Username/password combination not accepted.");
				else
					Server.BeginReceive(Buffer, Received, Buffer.Length - Received, SocketFlags.None, new AsyncCallback(this.OnReceive), Server);
			}
            catch (Exception e)
            {
				CallBack(e);
			}
		}
		
		private string Username
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
		
		private string m_Username;
		private string m_Password;
	}
}