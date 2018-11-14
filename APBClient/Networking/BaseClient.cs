using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Reflection;
using APBClient.Crypto;
using Org.Mentalis.Network.ProxySocket;

namespace APBClient.Networking
{
    public abstract class BaseClient
    {
        private const int RecvBufferSize = 65535;

        private ISocketFactory SocketFactory;
        private ProxySocket Socket;
        private byte[] RecvBuffer = new byte[RecvBufferSize];
        private int NextPacketLength, ReceivedLength;
        private NetworkRc4 Encryption = new NetworkRc4();
        private Dictionary<uint, Tuple<string, Action<BaseClient, ServerPacket>>> _packetHandlers = new Dictionary<uint, Tuple<string, Action<BaseClient, ServerPacket>>>();

        public event EventHandler<EventArgs> OnConnectSuccess = delegate { };
        public event EventHandler<Exception> OnConnectFailed = delegate { };
        public event EventHandler<EventArgs> OnDisconnect = delegate { };

        public BaseClient(ISocketFactory socketFactory = null)
        {
            if (socketFactory == null)
                SocketFactory = new StandardSocketFactory();
            else
                SocketFactory = socketFactory;
            
            SetupHandlers();
        }

        public void Connect(string host, int port)
        {
            ReceivedLength = 0;
            Encryption.Initialized = false;
            Socket = SocketFactory.CreateSocket();
            Socket.BeginConnect(host, port, ConnectCallback, null);
        }

        private void ConnectCallback(IAsyncResult ar)
        {
            try
            {
                Socket.EndConnect(ar);
                OnConnectSuccess(this, null);
                PostConnect();
                BeginReceiveLength();

            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
                OnConnectFailed(this, e);
                Disconnect();
            }
        }

        protected virtual void PostConnect() { }

        public void Disconnect()
        {
            if (Socket == null)
                return;

            try
            {
                Socket.Disconnect(false);
                Socket.Close();
                Socket = null;
            }
            catch (ObjectDisposedException) {}
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
            OnDisconnect(this, null);
        }

        private void BeginReceiveLength()
        {
            Socket.BeginReceive(RecvBuffer, ReceivedLength, 4 - ReceivedLength, SocketFlags.None, ReceiveLengthCallback, null);
        }

        private void BeginReceiveData()
        {
            Socket.BeginReceive(RecvBuffer, ReceivedLength, NextPacketLength - ReceivedLength, SocketFlags.None, ReceiveDataCallback, null);
        }

        private void ReceiveLengthCallback(IAsyncResult ar)
        {
            if (Socket == null)
                return;

            try
            {
                int length = Socket.EndReceive(ar);
                if (length <= 0)
                {
                    Disconnect();
                    return;
                }

                ReceivedLength += length;
                if (ReceivedLength == 4)
                {
                    NextPacketLength = BitConverter.ToInt32(RecvBuffer, 0) - 4;
                    ReceivedLength = 0;
                    BeginReceiveData();
                }
                else
                    BeginReceiveLength();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
                Disconnect();
            }
        }

        private void ReceiveDataCallback(IAsyncResult ar)
        {
            if (Socket == null)
                return;

            try
            {
                int length = Socket.EndReceive(ar);
                if (length <= 0)
                {
                    Disconnect();
                    return;
                }

                ReceivedLength += length;
                if (ReceivedLength == NextPacketLength)
                {
                    TryParsePacket();
                    BeginReceiveLength();
                }
                else
                    BeginReceiveData();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
                Disconnect();
            }
        }

        private bool TryParsePacket()
        {
            if (Encryption.Initialized)
                Encryption.DecryptServerData(RecvBuffer, 0, ReceivedLength);

            var packet = new ServerPacket(RecvBuffer, 0, ReceivedLength);
            ReceivedLength = 0;
            HandlePacket(packet);
            return true;
        }

        protected void HandlePacket(ServerPacket packet)
        {
            if (_packetHandlers.ContainsKey(packet.OpCode))
            {
                var handlerData = _packetHandlers[packet.OpCode];
                handlerData.Item2(this, packet);
            }
            else
            {
                string dir = $"PacketDumps/{packet.OpCode}";
                if (!Directory.Exists(dir))
                    Directory.CreateDirectory(dir);

                string date = "_" + DateTime.Now.Day + DateTime.Now.Month + DateTime.Now.Year + DateTime.Now.Hour + DateTime.Now.Minute + DateTime.Now.Second;
                File.WriteAllText($"PacketDumps/{packet.OpCode}/{date}_hex", Util.HexDump(packet.Data));
                File.WriteAllBytes($"PacketDumps/{packet.OpCode}/{date}_byte", packet.Data);
            }
        }

        protected void SetEncryptionKey(byte[] key)
        {
            Encryption.SetKey(key);
        }

        protected void SendPacket(ClientPacket packet)
        {
            byte[] data = packet.GetDataForSending();
            if (Encryption.Initialized)
                Encryption.EncryptClientData(data, 4, packet.TotalSize - 4);

            Socket.Send(data, 0, packet.TotalSize, SocketFlags.None); 
        }

        private void SetupHandlers()
        {
            Type[] types = GetType().GetNestedTypes(BindingFlags.NonPublic | BindingFlags.Public);
            foreach (Type type in types)
            {
                if (!type.IsClass)
                    continue;

                if (!type.GetInterfaces().Contains(typeof(IPacketHandler)))
                    continue;

                PacketHandlerAttribute attribute = (PacketHandlerAttribute)type.GetCustomAttribute(typeof(PacketHandlerAttribute));
                if (attribute == null)
                    continue;

                uint opCode = (uint)attribute.OpCode;

                var handlerInstance = Activator.CreateInstance(type);
                var handlerDel = (Action<BaseClient, ServerPacket>)Delegate.CreateDelegate(typeof(Action<BaseClient, ServerPacket>), handlerInstance, "HandlePacket");

                _packetHandlers.Add(opCode, Tuple.Create(type.Name, handlerDel));
            }
        }
    }
}