using System;
using APBClient.Crypto;
using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_LOGIN_PUZZLE)]
        private class LS2GC_LOGIN_PUZZLE : BasePacketHandler<LobbyClient>
        {
            private void SolveLoginPuzzle(uint[] v, uint[] k, byte unknown)
            {
                for (uint guess = 0; guess < uint.MaxValue; guess++)
                {
                    k[3] = guess;
                    uint[] vClone = (uint[])v.Clone();
                    XXTEA.Encrypt(vClone, k, 6);
                    uint solution = vClone[1];

                    if (solution >> (32 - unknown) == 0 && (solution & (0x80000000 >> unknown)) != 0)
                        return;
                }
                throw new Exception("Failed to solve login puzzle");
            }

            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                int versionHigh = reader.ReadInt32(), versionMiddle = reader.ReadInt32(), versionLow = reader.ReadInt32(), buildNo = reader.ReadInt32();
                byte unknown = reader.ReadByte();
                uint puzzleSolution = 0;
                if (unknown > 0)
                {
                    byte[] encryptionKey = reader.ReadBytes(8);
                    client.SetEncryptionKey(encryptionKey);

                    uint[] uintEncryptionKey = new uint[2];
                    uintEncryptionKey[0] = BitConverter.ToUInt32(encryptionKey, 0);
                    uintEncryptionKey[1] = BitConverter.ToUInt32(encryptionKey, 4);

                    uint[] puzzleData = new uint[4];
                    puzzleData[3] = 0;
                    for (int i = 0; i < 3; i++)
                        puzzleData[i] = reader.ReadUInt32();

                    try
                    {
                        SolveLoginPuzzle(uintEncryptionKey, puzzleData, unknown);
                    }
                    catch (Exception)
                    {
                        client.OnPuzzleFailed(client, 10011);
                        client.Disconnect();
                        return;
                    }
                    puzzleSolution = puzzleData[3];
                }
                var askLogin = new GC2LS_ASK_LOGIN(puzzleSolution, client.Username, 0);
                client.SendPacket(askLogin);
            }
        }
    }
}