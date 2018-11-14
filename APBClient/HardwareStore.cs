using Org.BouncyCastle.Crypto.Digests;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Xml;
using YamlDotNet.Serialization;

namespace APBClient
{
    public class HardwareStore
    {
        private class WmiSection
        {
            public string Select { get; set; }
            public string From { get; set; }
            public List<string> NumericFields { get; set; }
            public List<Dictionary<string, string>> Data { get; set; }

            public WmiSection()
            {
                NumericFields = new List<string>();
                Data = new List<Dictionary<string, string>>();
            }
        }

        private class WindowsVersionInfo
        {
            public int MajorVersion { get; set; }
            public int MinorVersion { get; set; }
            public int ProductType { get; set; }
            public int BuildNumber { get; set; }
        }

        private class HardwareDb
        {
            public Dictionary<string, WmiSection> WmiSections { get; set; }
            public string SmbiosVersion { get; set; }
            public int BfpVersion { get; set; }
            public Dictionary<string, Dictionary<string, string>> BfpSections { get; set; }
            public string HddGuid { get; set; }
            public WindowsVersionInfo WindowsVersion { get; set; }
            public uint InstallDate { get; set; }
        }

        private readonly HardwareDb HardwareDB;
        public int BfpVersion => HardwareDB.BfpVersion;

        public HardwareStore(TextReader reader)
        {
            var deserializer = new Deserializer();
            HardwareDB = deserializer.Deserialize<HardwareDb>(reader);
        }

        private WmiSection GetSection(string sectionName)
        {
            if (!HardwareDB.WmiSections.ContainsKey(sectionName))
                throw new Exception($"No WMI data present for {sectionName}");

            return HardwareDB.WmiSections[sectionName];
        }

        public byte[] BuildWindowsInfo()
        {
            var data = new byte[33];
            Buffer.BlockCopy(BitConverter.GetBytes(HardwareDB.WindowsVersion.MajorVersion), 0, data, 0, 4);
            Buffer.BlockCopy(BitConverter.GetBytes(HardwareDB.WindowsVersion.MinorVersion), 0, data, 4, 4);
            Buffer.BlockCopy(BitConverter.GetBytes(HardwareDB.WindowsVersion.ProductType), 0, data, 8, 1);
            Buffer.BlockCopy(BitConverter.GetBytes(HardwareDB.WindowsVersion.BuildNumber), 0, data, 9, 4);
            Buffer.BlockCopy(BitConverter.GetBytes(HardwareDB.InstallDate), 0, data, 13, 4);
            Buffer.BlockCopy(Guid.Parse(HardwareDB.HddGuid).ToByteArray(), 0, data, 17, 16);
            return data;
        }

        public void BuildBfpSection(XmlWriter writer)
        {
            writer.WriteStartElement("BFP");
            writer.WriteAttributeString("bfp_v", HardwareDB.BfpVersion.ToString());
            writer.WriteAttributeString("smb_v", HardwareDB.SmbiosVersion);
            foreach (var section in HardwareDB.BfpSections)
            {
                var sectionName = section.Key;
                var data = section.Value;
                writer.WriteStartElement(sectionName);
                if (sectionName == "SLOTS")
                    writer.WriteAttributeString("Num", data.Count.ToString());
                
                foreach (var entry in data)
                {
                    var entryName = entry.Key;
                    var entryData = entry.Value;

                    if (sectionName == "BIOS" && entryName == "RomSize")
                    {
                        var size = (int.Parse(entryData) + 1)*64;
                        writer.WriteElementString("RomSize", $"Bios Rom Size: {entryData} ({size}K) == 64K * ({entryData}+1)");
                    }
                    else
                        writer.WriteElementString(entry.Key, entry.Value);
                }
                writer.WriteEndElement();
            }
            writer.WriteEndElement();
        }

        public byte[] BuildBfpHash()
        {
            var memStream = new MemoryStream(512);
            var writer = new BinaryWriter(memStream);
            var bfp = HardwareDB.BfpSections;
            foreach (var section in bfp)
            {
                var sectionName = section.Key;
                if (sectionName == "SLOTS")
                    writer.Write((ushort)section.Value.Count);
                else
                {
                    foreach (var entry in section.Value)
                    {
                        var name = entry.Key;
                        var data = entry.Value;

                        if (sectionName == "BIOS" && name == "RomSize")
                            writer.Write(byte.Parse(data));
                        else if (sectionName == "SYSINFO" && name == "UUID")
                            writer.Write(Guid.Parse(data).ToByteArray());
                        else if ((sectionName == "CHASSIS" || sectionName == "PROCESSOR") && name == "Type")
                            writer.Write(byte.Parse(data));
                        else if (sectionName == "PROCESSOR" && name == "Family")
                            writer.Write(byte.Parse(data));
                        else if (sectionName == "PROCESSOR" && name == "RawId") { }
                        else if (sectionName == "MEMSLOTS" && name == "MaxCapacity")
                            writer.Write(ulong.Parse(data));
                        else if (sectionName == "MEMSLOTS" && name == "NumMemoryDevices")
                            writer.Write(ushort.Parse(data));
                        else
                            writer.Write(Encoding.ASCII.GetBytes(data));
                    }
                }
            }

            byte[] hashData = memStream.ToArray();
            var sha1 = new Sha1Digest();
            sha1.BlockUpdate(hashData, 0, hashData.Length);
            var hash = new byte[sha1.GetDigestSize()];
            sha1.DoFinal(hash, 0);
            return hash;
        }

        public byte[] BuildWmiSectionAndHash(XmlWriter writer, string sectionName, string select, string from, bool skipHash)
        {
            WmiSection section = GetSection(sectionName);
            if (section.Select != select || section.From != from);

            var stringValues = new List<string>();
            var numericValues = new List<int>();
            
            string[] fieldNames = select.Split(',');
            writer.WriteStartElement(sectionName);
            if (skipHash)
                writer.WriteAttributeString("s", "1");

            for (int i = 0; i < section.Data.Count; i++)
            {
                var dataEntry = section.Data[i];
                foreach (var fieldName in fieldNames)
                {
                    bool isSkipField = false;
                    string actualFieldName = fieldName;
                    if (fieldName.StartsWith("@"))
                    {
                        isSkipField = true;
                        actualFieldName = fieldName.Substring(1);
                    }

                    if (!dataEntry.ContainsKey(actualFieldName))
                        continue;

                    string fieldValue = dataEntry[actualFieldName];
                    writer.WriteStartElement(actualFieldName);
                    writer.WriteAttributeString("n", (i+1).ToString());

                    if (isSkipField || skipHash)
                        writer.WriteAttributeString("s", "1");
                    else
                    {
                        if (section.NumericFields.Contains(fieldName))
                            numericValues.Add(int.Parse(fieldValue));   
                        else
                            stringValues.Add(fieldValue);
                    }

                    writer.WriteValue(fieldValue);
                    writer.WriteEndElement();
                }
            }

            writer.WriteEndElement();
            if (!skipHash)
            {
                numericValues.Sort();
                stringValues.Sort();

                var sha1 = new Sha1Digest();
                foreach (int value in numericValues)
                    sha1.BlockUpdate(BitConverter.GetBytes(value), 0, 4);

                foreach (string value in stringValues)
                {
                    byte[] rawData = Encoding.Unicode.GetBytes(value);
                    sha1.BlockUpdate(rawData, 0, rawData.Length);
                }

                byte[] hash = new byte[sha1.GetDigestSize()];
                sha1.DoFinal(hash, 0);
                return hash;
            }
            return null;
        }
    }
}