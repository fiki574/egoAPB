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

namespace Org.Mentalis.Network.ProxySocket
{
	public class ProxyException : Exception
    {
		public ProxyException() : this("An error occured while talking to the proxy server.") {}
		public ProxyException(string message) : base(message) {}
		public ProxyException(int socks5Error) : this(Socks5ToString(socks5Error)) {}

        public static string Socks5ToString(int socks5Error)
        {
			switch(socks5Error)
            {
				case 0:
					return "Connection succeeded.";
				case 1:
					return "General SOCKS server failure.";
				case 2:
					return "Connection not allowed by ruleset.";
				case 3:
					return "Network unreachable.";
				case 4:
					return "Host unreachable.";
				case 5:
					return "Connection refused.";
				case 6:
					return "TTL expired.";
				case 7:
					return "Command not supported.";
				case 8:
					return "Address type not supported.";
				default:
					return "Unspecified SOCKS error.";
			}
		}
	}
}