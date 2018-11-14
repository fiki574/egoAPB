﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Xml;
using APBClient.Crypto;
using APBClient.IO;
using APBClient.Networking;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        [PacketHandler(APBOpCode.LS2GC_WMI_REQUEST)]
        private class LS2GC_WMI_REQUEST : BasePacketHandler<LobbyClient>
        {
            public override void HandlePacket(LobbyClient client, ServerPacket packet)
            {
                var reader = packet.Reader;
                uint hwVValue = reader.ReadUInt32();
                int encryptedDataSize = reader.ReadInt32();
                byte[] encryptedData = reader.ReadBytes(encryptedDataSize);
                byte[] decryptedData = WindowsRSA.DecryptData(client._clientDecryptEngine, encryptedData);
                var dataReader = new APBBinaryReader(new MemoryStream(decryptedData));

                string queryLanguage = dataReader.ReadASCIIString(4);
                if (queryLanguage != "WQL")
                {
                    client.Disconnect();
                    return;
                }

                int numSections = dataReader.ReadInt32();
                int numFields = dataReader.ReadInt32();

                XmlWriterSettings settings = new XmlWriterSettings();
                settings.OmitXmlDeclaration = true;

                var hashes = new List<byte[]>(numSections);

                StringBuilder hwBuilder = new StringBuilder();
                XmlWriter hwWriter = XmlWriter.Create(hwBuilder, settings);

                hwWriter.WriteStartElement("HW");
                hwWriter.WriteAttributeString("v", hwVValue.ToString());

                for (int i = 0; i < numSections; i++)
                {
                    byte sectionNumber = dataReader.ReadByte();
                    byte sectionNameLength = dataReader.ReadByte();
                    string sectionName = dataReader.ReadASCIIString(sectionNameLength + 1);
                    byte skipHash = dataReader.ReadByte();
                    byte selectLength = dataReader.ReadByte();
                    string selectClause = dataReader.ReadASCIIString(selectLength + 1);
                    byte fromLength = dataReader.ReadByte();
                    string fromClause = dataReader.ReadASCIIString(fromLength + 1);
                    byte[] hash = client._hardwareStore.BuildWmiSectionAndHash(hwWriter, sectionName, selectClause, fromClause, (skipHash == 1));
                    if (hash != null)
                        hashes.Add(hash);
                }

                hwWriter.WriteEndElement();
                hwWriter.Flush();

                byte[] hashBlock = new byte[4 * hashes.Count];
                for (int i = 0; i < hashes.Count; i++)
                    Buffer.BlockCopy(hashes[i], 0, hashBlock, i * 4, 4);

                StringBuilder bfpBuilder = new StringBuilder();
                XmlWriter bfpWriter = XmlWriter.Create(bfpBuilder, settings);
                client._hardwareStore.BuildBfpSection(bfpWriter);
                bfpWriter.Flush();

                byte[] bfpHash = client._hardwareStore.BuildBfpHash();
                byte[] windowsInfo = client._hardwareStore.BuildWindowsInfo();
                byte[] hwUnicodeData = Encoding.Unicode.GetBytes(hwBuilder.ToString());
                byte[] bfpUnicodeData = Encoding.Unicode.GetBytes(bfpBuilder.ToString());
                byte[] encryptedHWData = WindowsRSA.EncryptData(client._serverEncryptEngine, hwUnicodeData);
                byte[] encryptedBFPData = WindowsRSA.EncryptData(client._serverEncryptEngine, bfpUnicodeData);
                byte[] encryptedHashBlock = WindowsRSA.EncryptData(client._serverEncryptEngine, hashBlock);
                var hardwareInfo = new GC2LS_HARDWARE_INFO(windowsInfo, 0, 0, client._hardwareStore.BfpVersion, bfpHash, encryptedHashBlock, encryptedBFPData, encryptedHWData);
                client.SendPacket(hardwareInfo);
            }
        }
    }
}