﻿using System.Text;
using System.IO;

namespace APBClient.IO
{
    public class APBBinaryWriter : BinaryWriter
    {
        public APBBinaryWriter(Stream output) : base(output) { }

        public void WriteUnicodeString(string str, int fieldSize)
        {
            byte[] bytes = Encoding.Unicode.GetBytes(str);

            int i;
            for (i = 0; i < bytes.Length && i < fieldSize; i++)
                Write(bytes[i]);

            if (i < fieldSize)
                for (; i < fieldSize; i++)
                    Write((byte)0);
        }
    }
}