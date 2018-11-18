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

                /*
                21:26:20 - ScriptLog: (cHostingGC2WS_0) cHostingGC2WS::OnDistrictEnterSuccess()
                21:26:20 - ScriptLog: (cHostingClient_0) ClientState kCLIENT_STATE_DISTRICT_ENTER1_COMPLETE
                21:26:20 - Log: Connecting to DistrictServer
                21:26:20 - ScriptLog: (cHostingClient_0) ClientState kCLIENT_STATE_DISTRICTSERVER_CONNECT_IN_PROGRESS
                21:26:20 - Init: WinSock: Socket queue 32768 / 32768
                21:26:20 - Init: WinSock: I am DESKTOP-2UIF4CE (192.168.1.6:0)
                21:26:20 - Log: [FSocketWin::Bind] Binding to 0.0.0.0:0
                21:26:20 - DevNet: Game client on port 10200
                ...
                21:26:20 - DevNet: Sending AUTH ACCID=0022424338
                21:26:20 - DevNet: PendingLevel received: HandshakeChallenge
                21:26:20 - DevNet: PendingLevel received: HandshakeComplete
                21:26:20 - DevNet: PendingLevel received: Uses
                ...
                21:26:22 - ScriptLog: (cAPBPlayerController_1) cHostingPlayerController::InitInputSystem()
                21:26:22 - ScriptLog: (cAPBPlayerController_1) RemoteRole == ROLE_Authority
                21:26:22 - ScriptLog: (cAPBPlayerController_1) Calling Send_GC2DS_ASK_DISTRICT_ENTER()
                21:26:22 - ScriptLog: (cAPBPlayerController_1) Send [GC2DS_ASK_DISTRICT_ENTER]
                ...
                21:26:25 - ScriptLog: (cAPBPlayerController_1) Receive [DS2GC_ANS_DISTRICT_ENTER]
                21:26:25 - ScriptLog: (cAPBPlayerController_1) m_nReturnCode 0
                21:26:25 - ScriptLog: (cAPBPlayerController_1) m_nDistrictUID 16
                21:26:25 - ScriptLog: (cAPBPlayerController_1) m_nInstanceNo 1
                */
            }
        }
    }
}