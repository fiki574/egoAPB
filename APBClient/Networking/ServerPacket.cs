using System;
using System.IO;
using APBClient.IO;

namespace APBClient.Networking
{
    public class ServerPacket
    {
        public byte[] Data { get; }
        public APBBinaryReader Reader { get; }
        public uint OpCode { get; }

        public ServerPacket(byte[] dataBuf, int bufOffset, int size)
        {
            Data = new byte[size];
            Buffer.BlockCopy(dataBuf, bufOffset, Data, 0, size);
            Reader = new APBBinaryReader(new MemoryStream(Data));
            OpCode = Reader.ReadUInt32();
        }
    }
}