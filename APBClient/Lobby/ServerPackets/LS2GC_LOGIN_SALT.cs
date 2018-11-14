using System.Text;
using APBClient.Crypto;
using APBClient.Networking;
using Org.BouncyCastle.Crypto.Digests;
using Org.BouncyCastle.Math;
using Org.BouncyCastle.Security;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_LOGIN_SALT)]
        private class LS2GC_LOGIN_SALT : BasePacketHandler<LobbyClient>
        {
            private const string Modulus = "11144252439149533417835749556168991736939157778924947037200268358613863350040339017097790259154750906072491181606044774215413467851989724116331597513345603";
            private static readonly byte[] Generator = { 0x02 };

            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                var srpClient = new WeakSrp6Client();
                var secureRandom = new SecureRandom();
                srpClient.Init(new BigInteger(Modulus), new BigInteger(Generator), new Sha1Digest(), secureRandom);

                uint accountId = reader.ReadUInt32();
                byte[] serverB = reader.ReadBytes(64);
                ushort serverBLen = reader.ReadUInt16();
                byte[] salt = reader.ReadBytes(10);

                client._accountId = accountId;

                BigInteger serverBInt = new BigInteger(1, serverB, 0, serverBLen);
                byte[] usernameBytes = Encoding.ASCII.GetBytes(accountId.ToString());
                byte[] passwordBytes = Encoding.ASCII.GetBytes(client._password);

                BigInteger clientPub = srpClient.GenerateClientCredentials(salt, usernameBytes, passwordBytes);
                srpClient.CalculateSecret(serverBInt);
                client._srpKey = srpClient.CalculateSessionKey().ToByteArrayUnsigned();

                BigInteger proof = srpClient.CalculateClientEvidenceMessage();

                var loginProof = new GC2LS_LOGIN_PROOF(clientPub.ToByteArrayUnsigned(), proof.ToByteArrayUnsigned());
                client.SendPacket(loginProof);
            }
        }
    }
}