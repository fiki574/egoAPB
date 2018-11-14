using System;
using System.IO;
using System.Collections.Generic;
using APBClient;
using APBClient.Lobby;
using APBClient.World;
using System.Threading.Tasks;

namespace egoAPB
{
    class Program
    {
        static void Main(string[] args)
        {
            string username = "user", password = "pass";

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
                    Console.WriteLine("Logged in");

                    List<CharacterInfo> characters = client.GetCharacters();
                    Console.WriteLine("Got characters");

                    CharacterInfo.Detailed charinfo = await client.GetDetailedCharacterInfo(characters[2].SlotNumber);
                    Console.WriteLine("Got details for characters");

                    List<WorldInfo> worlds = await client.GetWorlds();
                    Console.WriteLine("Received worlds");

                    FinalWorldEnterData worldEnterData = await client.EnterWorld(characters[2].SlotNumber); 
                    Console.WriteLine("Connected to world");

                    ClanInfo clanInfo = client.GetClanInfo();
                    clanInfo.MOTD = client.GetClanMOTD();
                    Console.WriteLine("Got clan info");

                    Dictionary<int, DistrictInfo> districts = client.GetDistricts();
                    Console.WriteLine("Got districts");

                    List<InstanceInfo> instances = await client.GetInstances();
                    Console.WriteLine("Received instances");
                }
                catch (Exception e)
                {
                    Console.WriteLine("Error occurred");
                    Console.WriteLine(e);
                }
            }).Wait();
            Console.ReadKey();
        }
    }
}