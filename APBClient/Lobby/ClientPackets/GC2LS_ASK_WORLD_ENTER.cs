﻿using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        private class GC2LS_ASK_WORLD_ENTER : ClientPacket
        {
            public GC2LS_ASK_WORLD_ENTER(int characterSlot)
            {
                OpCode = (uint)APBOpCode.GC2LS_ASK_WORLD_ENTER;

                AllocateData(9);
                Writer.Write((byte)characterSlot);
            }
        }
    }
}