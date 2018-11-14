﻿using APBClient.Crypto;
using APBClient.Networking;
using Org.BouncyCastle.Crypto;
using Org.BouncyCastle.Crypto.Encodings;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Generators;
using Org.BouncyCastle.Crypto.Parameters;
using Org.BouncyCastle.Security;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_ANS_LOGIN_SUCCESS)]
        private class LS2GC_ANS_LOGIN_SUCCESS : BasePacketHandler<LobbyClient>
        {
            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                string realTag = reader.ReadUnicodeString(50);
                uint accountPremium = reader.ReadUInt32();
                ulong timeStamp = reader.ReadUInt64();
                ulong accountPermissions = reader.ReadUInt64();
                for (int i = 0; i < 5; i++)
                    reader.ReadInt32();

                ushort voicePortMin = reader.ReadUInt16();
                ushort voicePortMax = reader.ReadUInt16();
                uint voiceAccountId = reader.ReadUInt32();
                string voiceUsername = reader.ReadASCIIString(17);
                string voiceKey = reader.ReadASCIIString(17);

                RsaKeyParameters serverPub = WindowsRSA.ReadPublicKeyBlob(reader);
                string countryCode = reader.ReadUnicodeString();
                string voiceURL = reader.ReadASCIIString();

                var generator = new RsaKeyPairGenerator();
                generator.Init(new KeyGenerationParameters(new SecureRandom(), 1024));
                AsymmetricCipherKeyPair clientKeyPair = generator.GenerateKeyPair();
                RsaKeyParameters clientPub = (RsaKeyParameters)clientKeyPair.Public;

                client._clientDecryptEngine = new Pkcs1Encoding(new RsaEngine());
                client._clientDecryptEngine.Init(false, clientKeyPair.Private);

                byte[] clientPubBlob = WindowsRSA.CreatePublicKeyBlob(clientPub);
                client._serverEncryptEngine = new Pkcs1Encoding(new RsaEngine());
                client._serverEncryptEngine.Init(true, serverPub);

                byte[] encryptedClientKey = WindowsRSA.EncryptData(client._serverEncryptEngine, clientPubBlob);
                client.SetEncryptionKey(client._srpKey);

                var keyExchange = new GC2LS_KEY_EXCHANGE(encryptedClientKey);
                client.SendPacket(keyExchange);

                client.OnLoginSuccess(client, null);
            }
        }
    }
}