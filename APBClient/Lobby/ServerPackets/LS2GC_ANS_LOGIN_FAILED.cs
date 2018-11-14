﻿using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_ANS_LOGIN_FAILED)]
        private class LS2GC_ANS_LOGIN_FAILED : BasePacketHandler<LobbyClient>
        {
            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                var data = new LoginFailedData
                {
                    ReturnCode = reader.ReadUInt32(),
                    CountryCode = reader.ReadUnicodeString(48)
                };
                client.OnLoginFailed(client, data);
                client.Disconnect();
            }
        }
    }
}