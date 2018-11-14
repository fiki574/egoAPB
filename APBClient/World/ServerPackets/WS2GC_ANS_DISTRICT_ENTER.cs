using System;
using APBClient.Networking;
using System.Net;
using Org.BouncyCastle.Crypto.Digests;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_ANS_DISTRICT_ENTER)]
        private class WS2GC_ANS_DISTRICT_ENTER : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                int returnCode = reader.ReadInt32();
                if (returnCode != 0)
                {
                    client.OnDistrictEnterFailed(client, returnCode);
                    return;
                }

                var data = new DistrictEnterInfo()
                {
                    ReturnCode = returnCode,
                    DistrictServerIpAddress = new IPAddress(reader.ReadBytes(4)),
                    DistrictServerPort = reader.ReadUInt16(),
                    Timestamp = reader.ReadUInt64(),
                };

                var timestampBytes = BitConverter.GetBytes(data.Timestamp);
                var sha1 = new Sha1Digest();
                sha1.BlockUpdate(client.EncryptionKey, 0, client.EncryptionKey.Length);
                sha1.BlockUpdate(timestampBytes, 0, timestampBytes.Length);
                var handshakeHash = new byte[sha1.GetDigestSize()];
                sha1.DoFinal(handshakeHash, 0);

                data.HandshakeHash = handshakeHash;

                sha1 = new Sha1Digest();
                sha1.BlockUpdate(client.EncryptionKey, 0, client.EncryptionKey.Length);
                sha1.BlockUpdate(handshakeHash, 0, handshakeHash.Length);
                var encryptionHash = new byte[sha1.GetDigestSize()];
                sha1.DoFinal(encryptionHash, 0);
                var encryptionKey = new byte[16];
                Buffer.BlockCopy(encryptionHash, 0, encryptionKey, 0, 16);

                data.XXTEAKey = encryptionKey;
                client.OnDistrictEnterSuccess(client, data);
            }
        }
    }
}