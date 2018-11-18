﻿using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        private class GC2LS_HARDWARE_INFO : ClientPacket
        {
            public GC2LS_HARDWARE_INFO(byte[] windowsInfo, int a2, int a3, int bfpVersion, byte[] bfpHash, byte[] hashSection, byte[] bfpData, byte[] hwData)
            {
                OpCode = (uint)APBOpCode.GC2LS_HARDWARE_INFO;
                AllocateData(8 + windowsInfo.Length + 4 + 4 + 4 + bfpHash.Length + hashSection.Length + 4 + 4 + bfpData.Length + hwData.Length);
                Writer.Write(windowsInfo);
                Writer.Write(a2); 
                Writer.Write(a3);
                Writer.Write(bfpVersion);
                Writer.Write(bfpHash);
                Writer.Write(hashSection);
                Writer.Write(bfpData.Length);
                Writer.Write(hwData.Length);
                Writer.Write(bfpData);
                Writer.Write(hwData);
            }
        }
    }
}