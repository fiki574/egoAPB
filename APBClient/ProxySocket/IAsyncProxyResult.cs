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
using System.Threading;

namespace Org.Mentalis.Network.ProxySocket
{
	internal class IAsyncProxyResult : IAsyncResult
    {
		internal void Init(object stateObject)
        {
			m_StateObject = stateObject;
			m_Completed = false;
			if (m_WaitHandle != null)
				m_WaitHandle.Reset();
		
		}
		internal void Reset()
        {
			m_StateObject = null;
			m_Completed = true;
			if (m_WaitHandle != null)
				m_WaitHandle.Set();
		}
		
		public bool IsCompleted
        {
			get
            {
				return m_Completed;
			}
		}
		
		public bool CompletedSynchronously
        {
			get
            {
				return false;
			}
		}
		
		public object AsyncState
        {
			get
            {
				return m_StateObject;
			}
		}
		
		public WaitHandle AsyncWaitHandle
        {
			get
            {
				if (m_WaitHandle == null)
					m_WaitHandle = new ManualResetEvent(false);

				return m_WaitHandle;
			}
		}
		
		internal bool m_Completed = true;
		private object m_StateObject;
		private ManualResetEvent m_WaitHandle;
	}
}