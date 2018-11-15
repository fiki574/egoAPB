using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Collections.Generic;
using APBClient;
using APBClient.Lobby;
using APBClient.World;
using System.Threading.Tasks;
using System.Linq;

namespace egoAPB
{
    class Program
    {
        static void Main(string[] args)
        {
            string username = "user", password = "pass", character = "char";

            if (!Directory.Exists("PacketDumps"))
                Directory.CreateDirectory("PacketDumps");

            HardwareStore hw;
            using (TextReader reader = File.OpenText("hw.yml"))
                hw = new HardwareStore(reader);

            Task.Run(async () =>
            {
                try
                {
                    var client = new APBClient.APBClient(username, password, hw);
                    await client.Login();
                    Console.WriteLine("Connected to lobby server");

                    List<CharacterInfo> characters = client.GetCharacters();
                    Console.WriteLine($"Got {characters.Count} characters (threat: '{characters[0].Threat}')");
                    Console.WriteLine();

                    List<CharacterInfo.Detailed> detailed = new List<CharacterInfo.Detailed>(characters.Count);
                    foreach (var ch in characters)
                    {
                        CharacterInfo.Detailed charinfo = await client.GetDetailedCharacterInfo(ch.SlotNumber);
                        detailed.Add(charinfo);
                        Console.WriteLine($"Got details for character '{ch.CharacterName}'");
                        Console.WriteLine($"\t-> Faction: {ch.Faction.ToString()}\n\t-> Gender: {charinfo.Gender.ToString()}\n\t-> Money: {charinfo.Money}$\n\t-> Jocker Tickets: {charinfo.JokerTickets}\n\t-> Rank: {charinfo.Rank}\n\t-> Clan: {charinfo.Clan}");
                        Console.WriteLine();
                    }

                    CharacterInfo ChosenCharacter = characters.SingleOrDefault(c => c.CharacterName == character);
                    List<WorldInfo> worlds = await client.GetWorlds();
                    Console.WriteLine($"Got {worlds.Count} worlds");
                    foreach (var w in worlds)
                        Console.WriteLine($"\t-> {w.Name}, {w.Region}, {w.Status.ToString()}");

                    Console.WriteLine();
                    FinalWorldEnterData worldEnterData = await client.EnterWorld(ChosenCharacter.SlotNumber);
                    Console.WriteLine($"Connected to world server '{ChosenCharacter.WorldName}'");
                    Console.WriteLine();

                    try
                    {
                        ClanInfo clanInfo = client.GetClanInfo();
                        clanInfo.MOTD = client.GetClanMOTD();
                        Console.WriteLine($"Got clan info for '{clanInfo.Name}'");
                        string motd = clanInfo.MOTD;
                        motd = motd.Replace("\n", string.Empty);
                        motd = motd.Replace("\r", string.Empty);
                        motd = motd.Replace("\t", string.Empty);
                        Console.WriteLine($"\t-> Total members: {clanInfo.Members}\n\t-> Message of the day: {motd}\n\t-> Leader ID: {clanInfo.Leader}");
                        Console.WriteLine();
                    }
                    catch
                    {
                    }

                    Dictionary<int, DistrictInfo> districts = client.GetDistricts();
                    Console.WriteLine($"Got {districts.Count} districts");

                    List<InstanceInfo> instances = await client.GetInstances();
                    Console.WriteLine($"Got {instances.Count} instances");

                    foreach (var instance in instances)
                    {
                        string name = "Unknown-District-EN-0";
                        try
                        {
                            name = districts[instance.DistrictUid].Name;
                        }
                        catch
                        {
                        }

                        Console.WriteLine($"\t-> {name}-{instance.InstanceNum} ({instance.Enforcers} Enf, {instance.Criminals} Crim, Threat = {((ThreatType)instance.Threat).ToString()})");
                    }

                    Console.WriteLine();

                    /*
                    var instanceToJoin = (from instance in instances where instance.DistrictStatus == 0 && instance.Threat == 4 select instance).OrderBy(s => s.Criminals + s.Enforcers).First();
                    Console.WriteLine($"\t-> {name}-{instanceToJoin.InstanceNum}");
                    DistrictEnterInfo enterInfo = await client.JoinInstance(instanceToJoin);
                    */
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                }
            }).Wait();
            Console.ReadKey();
        }
    }
}