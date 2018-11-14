using System.IO;
using APBClient.IO;

namespace APBClient.Networking
{
    public class ClientPacket
    {
        private byte[] Data;
        protected APBBinaryWriter Writer { get; private set; }
        public int TotalSize { get; private set; }
        protected uint OpCode { get; set; }

        protected void AllocateData(int size)
        {
            Data = new byte[size];
            TotalSize = size;
            Writer = new APBBinaryWriter(new MemoryStream(Data));
            Writer.Seek(8, SeekOrigin.Begin);
        }

        public byte[] GetDataForSending()
        {
            Writer.Seek(0, SeekOrigin.Begin);
            Writer.Write(TotalSize);
            Writer.Write(OpCode);
            return Data;
        }
    }
}