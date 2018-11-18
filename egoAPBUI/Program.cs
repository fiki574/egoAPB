using System;
using System.Windows.Forms;
using System.IO;
using System.Collections.Generic;
using APBClient;
using APBClient.Lobby;
using APBClient.World;
using System.Threading.Tasks;
using System.Linq;

namespace egoAPBUI
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new LoginScreen());
        }

        static void Main2(/*USE THIS FOR UI DEV*/)
        {
            Console.Title = "egoAPB - External Game Observer for APB: Reloaded";
            string email = "mail", password = "pass", character = "char";

            if (!Directory.Exists("PacketDumps"))
                Directory.CreateDirectory("PacketDumps");

            HardwareStore hw;
            using (TextReader reader = File.OpenText("hw.yml"))
                hw = new HardwareStore(reader);

            Task.Run(async () =>
            {
                try
                {
                    var client = new APBClient.APBClient(email, password, hw);
                    await client.Login();
                    Console.WriteLine("Connected to lobby server");

                    List<CharacterInfo> characters = client.GetCharacters();
                    Console.WriteLine($"Got {characters.Count} characters (threat: '{characters[0].Threat}')");
                    Console.WriteLine();

                    foreach (var ch in characters)
                    {
                        CharacterInfo.Detailed charinfo = await client.GetDetailedCharacterInfo(ch.SlotNumber);
                        ch.Details = charinfo;
                        Console.WriteLine($"Got details for character '{ch.CharacterName}'");
                        Console.WriteLine($"\t-> Faction: {ch.Faction.ToString()}\n\t-> Gender: {charinfo.Gender.ToString()}\n\t-> Money: {ch.Details.Money}$\n\t-> Jocker Tickets: {ch.Details.JokerTickets}\n\t-> Rank: {ch.Details.Rank}\n\t-> Clan: {ch.Details.Clan}");
                        Console.WriteLine();
                    }

                    List<WorldInfo> worlds = await client.GetWorlds();
                    Console.WriteLine($"Got {worlds.Count} worlds");

                    //DONE TO THIS POINT
                    CharacterInfo ChosenCharacter = characters.SingleOrDefault(c => c.CharacterName == character);
                    worlds.ForEach(world => { Console.WriteLine($"\t-> {world.Name}, {world.Region}, {world.Status.ToString()}"); });
                    Console.WriteLine();
                    ChosenCharacter.WorldEnterData = await client.EnterWorld(ChosenCharacter.SlotNumber);
                    Console.WriteLine($"Connected to world server '{ChosenCharacter.WorldName}'");
                    Console.WriteLine();

                    try
                    {
                        ChosenCharacter.Clan = client.GetClanInfo();
                        ChosenCharacter.Clan.MOTD = client.GetClanMOTD();
                        Console.WriteLine($"Got clan info for '{ChosenCharacter.Clan.Name}'");
                        string motd = ChosenCharacter.Clan.MOTD.Replace("\n", string.Empty).Replace("\r", string.Empty).Replace("\t", string.Empty);
                        Console.WriteLine($"\t-> Total members: {ChosenCharacter.Clan.Members}\n\t-> Message of the day: {motd}\n\t-> Leader ID: {ChosenCharacter.Clan.Leader}");
                        Console.WriteLine();

                        ChosenCharacter.Friends = client.GetFriendList();
                        ChosenCharacter.Ignores = client.GetIgnoreList();
                        Console.WriteLine($"Got friendlist with {ChosenCharacter.Friends.TotalFriends} friends and ignorelist with {ChosenCharacter.Ignores.TotalIgnores} ignores");

                        ChosenCharacter.ChallengesInfo = client.GetChallenges();
                        Console.WriteLine($"Got info for {ChosenCharacter.ChallengesInfo.TotalChallenges} challenges");
                    }
                    catch
                    {
                    }

                    ChosenCharacter.MailsInfo = client.GetMailInfo();
                    Console.WriteLine($"Got total of {ChosenCharacter.MailsInfo.Total} mails in inbox (unread: {ChosenCharacter.MailsInfo.Unread}, expired: {ChosenCharacter.MailsInfo.Expired})");

                    Dictionary<int, DistrictInfo> districts = client.GetDistricts();
                    Console.WriteLine($"Got {districts.Count} districts");
                    Console.WriteLine();

                    List<InstanceInfo> instances = await client.GetInstances();
                    Console.WriteLine($"Got {instances.Count} instances");

                    instances.ForEach(instance => { Console.WriteLine($"\t-> {districts[instance.DistrictUid].Name}-{instance.InstanceNum} ({instance.Enforcers} Enf, {instance.Criminals} Crim, Threat = {((ThreatType)instance.Threat).ToString()})"); });
                    Console.WriteLine();

                    var instanceToJoin = (from instance in instances where instance.DistrictStatus == 0 && instance.Threat == (int)ChosenCharacter.Threat select instance).OrderBy(s => s.Criminals + s.Enforcers).First();
                    string inst = districts[instanceToJoin.DistrictUid].Name + "-" + instanceToJoin.InstanceNum;
                    DistrictEnterInfo enterInfo = await client.JoinInstance(instanceToJoin);
                    Console.WriteLine($"Joined {inst}");

                    Console.ReadKey();
                    client.Disconnect();
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    Console.ReadKey();
                }
            }).Wait();
        }
    }
}