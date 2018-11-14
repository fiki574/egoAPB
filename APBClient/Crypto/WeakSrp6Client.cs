using Org.BouncyCastle.Crypto.Agreement.Srp;
using Org.BouncyCastle.Math;
using Org.BouncyCastle.Crypto;
using Org.BouncyCastle.Crypto.Generators;
using Org.BouncyCastle.Crypto.Parameters;

namespace APBClient.Crypto
{
    internal class WeakSrp6Client : Srp6Client
    {
        protected byte[] Identity, Salt;

        public override BigInteger GenerateClientCredentials(byte[] salt, byte[] identity, byte[] password)
        {
            Identity = identity;
            Salt = salt;
            return base.GenerateClientCredentials(salt, identity, password);
        }

        public override BigInteger CalculateSessionKey()
        {
            if (S == null)
                throw new CryptoException("Impossible to compute Key: some data are missing from the previous operations (S)");

            byte[] output = new byte[40];
            Mgf1BytesGenerator generator = new Mgf1BytesGenerator(digest);
            generator.Init(new MgfParameters(S.ToByteArrayUnsigned()));
            generator.GenerateBytes(output, 0, output.Length);
            Key = new BigInteger(1, output);
            return Key;
        }

        public override BigInteger CalculateClientEvidenceMessage()
        {
            if (pubA == null || B == null || S == null || Key == null)
                throw new CryptoException("Impossible to compute M1: some data are missing from the previous operations (A,B,S,Key)");

            byte[] hN = new byte[digest.GetDigestSize()];
            byte[] bytesN = N.ToByteArrayUnsigned();
            digest.BlockUpdate(bytesN, 0, bytesN.Length);
            digest.DoFinal(hN, 0);

            byte[] hg = new byte[digest.GetDigestSize()];
            byte[] bytesg = g.ToByteArrayUnsigned();
            digest.BlockUpdate(bytesg, 0, bytesg.Length);
            digest.DoFinal(hg, 0);
            for (int i = 0; i < hN.Length; i++)
                hN[i] ^= hg[i];

            byte[] identityHash = new byte[digest.GetDigestSize()];
            digest.BlockUpdate(Identity, 0, Identity.Length);
            digest.DoFinal(identityHash, 0);
            
            digest.BlockUpdate(hN, 0, hN.Length);
            digest.BlockUpdate(identityHash, 0, identityHash.Length);
            digest.BlockUpdate(Salt, 0, Salt.Length);

            byte[] ABytes = pubA.ToByteArrayUnsigned();
            digest.BlockUpdate(ABytes, 0, ABytes.Length);

            byte[] BBytes = B.ToByteArrayUnsigned();
            digest.BlockUpdate(BBytes, 0, BBytes.Length);

            byte[] KeyBytes = Key.ToByteArrayUnsigned();
            digest.BlockUpdate(KeyBytes, 0, KeyBytes.Length);

            byte[] M1Bytes = new byte[digest.GetDigestSize()];
            digest.DoFinal(M1Bytes, 0);

            M1 = new BigInteger(1, M1Bytes);
            return M1;
        }

        protected override BigInteger SelectPrivateValue()
        {
            return new BigInteger(256, random);
        }
    }
}