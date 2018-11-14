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