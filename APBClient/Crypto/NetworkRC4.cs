using System.Security.Cryptography;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Parameters;

namespace APBClient.Crypto
{
    internal class NetworkRc4
    {
        private readonly RC4Engine ServerToClient = new RC4Engine();
        private readonly RC4Engine ClientToServer = new RC4Engine();

        public bool Initialized { get; set; }

        public void SetKey(byte[] key)
        {
            var sha1 = new SHA1CryptoServiceProvider();
            byte[] sha1Key = sha1.ComputeHash(key);
            var keyParam = new KeyParameter(sha1Key);
            ClientToServer.Init(true, keyParam);
            ServerToClient.Init(false, keyParam);
            Initialized = true;
        }

        public void EncryptClientData(byte[] data, int offset, int size)
        {
            ClientToServer.ProcessBytes(data, offset, size, data, offset);
        }

        public void DecryptServerData(byte[] data, int offset, int size)
        {
            ServerToClient.ProcessBytes(data, offset, size, data, offset);
        }
    }
}