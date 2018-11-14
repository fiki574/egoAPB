using Org.BouncyCastle.Crypto.Encodings;
using Org.BouncyCastle.Crypto.Parameters;
using Org.BouncyCastle.Math;
using System;
using System.Collections.Generic;
using System.IO;

namespace APBClient.Crypto
{
    internal class WindowsRSA
    {
        public static RsaKeyParameters ReadPublicKeyBlob(BinaryReader reader)
        {
            byte type = reader.ReadByte();
            byte version = reader.ReadByte();
            reader.ReadUInt16();
            uint algId = reader.ReadUInt32();

            if (type != 6 || version != 2 || algId != 0x0000A400)
                throw new Exception($"Unexpected public key header (Type = {type}, Version = {version}, AlgId = {algId})");

            byte[] magic = reader.ReadBytes(4);
            if (magic[0] != 0x52 || magic[1] != 0x53 || magic[2] != 0x41 || magic[3] != 0x31)
                throw new Exception($"Incorrect RSAPUBKEY magic ({magic[0]}, {magic[1]}, {magic[2]}, {magic[3]})");

            uint bitLength = reader.ReadUInt32();
            byte[] exponent = reader.ReadBytes(4);
            byte[] modulus = reader.ReadBytes((int)bitLength / 8);
            
            Array.Reverse(exponent);
            Array.Reverse(modulus);

            var pubKey = new RsaKeyParameters(false, new BigInteger(1, modulus), new BigInteger(1, exponent));
            return pubKey;
        }

        public static byte[] CreatePublicKeyBlob(RsaKeyParameters publicKey)
        {
            byte[] header = { 0x06, 0x02, 0x00, 0x00, 0x00, 0xA4, 0x00, 0x00, 0x52, 0x53, 0x41, 0x31 };
            byte[] bitLength = BitConverter.GetBytes(publicKey.Modulus.BitLength);
            byte[] exponent = publicKey.Exponent.ToByteArrayUnsigned();
            byte[] modulus = publicKey.Modulus.ToByteArrayUnsigned();

            int blobSize = header.Length + 4 + 4 + modulus.Length;
            byte[] blob = new byte[blobSize];

            Array.Reverse(exponent);
            Array.Reverse(modulus);

            Array.Clear(blob, 0, blob.Length);
            Buffer.BlockCopy(header, 0, blob, 0, header.Length);
            Buffer.BlockCopy(bitLength, 0, blob, 12, bitLength.Length);
            Buffer.BlockCopy(exponent, 0, blob, 16, exponent.Length);
            Buffer.BlockCopy(modulus, 0, blob, 20, modulus.Length);

            return blob;
        }

        public static byte[] EncryptData(Pkcs1Encoding engine, byte[] data)
        {
            int inputBlockSize = engine.GetInputBlockSize();
            int totalBlocks = (data.Length + inputBlockSize - 1) / inputBlockSize;

            byte[] result = new byte[totalBlocks * engine.GetOutputBlockSize()];

            int inputOffset = 0;
            int outputOffset = 0;

            while (inputOffset < data.Length)
            {
                int dataToConsume = Math.Min(inputBlockSize, data.Length - inputOffset);

                byte[] encryptedBlock = engine.ProcessBlock(data, inputOffset, dataToConsume);
                Array.Reverse(encryptedBlock);
                Buffer.BlockCopy(encryptedBlock, 0, result, outputOffset, encryptedBlock.Length);

                inputOffset += dataToConsume;
                outputOffset += encryptedBlock.Length;
            }
            return result;
        }

        public static byte[] DecryptData(Pkcs1Encoding engine, byte[] data)
        {
            int blockSize = engine.GetInputBlockSize();
            if (data.Length % blockSize != 0)
                throw new Exception("Cannot decrypt data, not a multiple of the output block size");

            int numBlocks = data.Length / blockSize;
            List<byte[]> decryptedBlocks = new List<byte[]>(numBlocks);
            int totalSize = 0;
            for (int i = 0; i < numBlocks; i++)
            {
                byte[] reversedData = new byte[blockSize];
                Buffer.BlockCopy(data, i * blockSize, reversedData, 0, blockSize);
                Array.Reverse(reversedData);
                byte[] decryptedBlock = engine.ProcessBlock(reversedData, 0, blockSize);
                decryptedBlocks.Add(decryptedBlock);
                totalSize += decryptedBlock.Length;
            }

            byte[] result = new byte[totalSize];
            int offset = 0;
            foreach (var block in decryptedBlocks)
            {
                Buffer.BlockCopy(block, 0, result, offset, block.Length);
                offset += block.Length;
            }
            return result;
        }
    }
}