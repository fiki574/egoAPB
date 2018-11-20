using System;
using System.IO;
using System.Linq;
using System.Windows.Forms;
using System.Threading.Tasks;
using System.Collections.Generic;
using APBClient;
using APBClient.Lobby;

namespace egoAPBUI
{
    public partial class MainScreen : Form
    {
        public static MainScreen Instance = null;
        public static List<CharacterInfo> Characters = null;
        public static List<WorldInfo> Worlds = null;

        public MainScreen()
        {
            InitializeComponent();
            Instance = this;
            Command.KeyDown += new KeyEventHandler(Command_KeyDown);
            FormClosed += new FormClosedEventHandler(MainScreenClosed);
        }

        private void MainScreen_Load(object sender, EventArgs e)
        {
            Task.Run(async () =>
            {
                try
                {
                    WriteLog("Connected to lobby server");
                    Characters = LoginScreen.client.GetCharacters();
                    WriteLog($"Got {Characters.Count} characters (threat: '{Characters[0].Threat}')");
                    foreach (var ch in Characters)
                    {
                        ch.Details = await LoginScreen.client.GetDetailedCharacterInfo(ch.SlotNumber);
                        WriteLog($"Got details for character '{ch.CharacterName}'");
                        File.WriteAllText($"Appearances/{ch.CharacterName}_hex", Util.HexDump(ch.Details.Appearance));
                        File.WriteAllBytes($"Appearances/{ch.CharacterName}_byte", ch.Details.Appearance);
                        CharactersList.Items.Add(ch.CharacterName);
                    }

                    Worlds = await LoginScreen.client.GetWorlds();
                    WriteLog($"Got {Worlds.Count} worlds");
                    Worlds.ForEach(world => { WriteLog($"-> {world.Name}, {world.Region}, {world.Status.ToString()}"); });
                }
                catch(Exception ex)
                {
                    WriteLog(ex.ToString());
                }
            }).Wait();
        }

        private void Command_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                SendCommand_Click(sender, null);
        }

        private void SendCommand_Click(object sender, EventArgs e)
        {
            //TODO
        }

        private void MainScreenClosed(object sender, FormClosedEventArgs e)
        {
            LoginScreen.client.Disconnect();
            LoginScreen.Instance.Show();
        }

        public void WriteLog(string message)
        {
            richTextBox1.Text += message + "\n";
        }

        private void CharactersList_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if(CharactersList.SelectedItem != null)
                {
                    string name = CharactersList.SelectedItem.ToString();
                    CharacterInfo ch = Characters.FirstOrDefault(c => c.CharacterName == name);
                    if(ch != null)
                    {
                        Threat.Text = $"Account threat: {ch.Threat.ToString()}";
                        SlotNumber.Text = $"Slot number: {ch.SlotNumber}";
                        Faction.Text = $"Faction: {ch.Faction}";
                        Gender.Text = $"Gender: {ch.Details.Gender.ToString()}";
                        WorldInfo.Text = $"World: {ch.WorldName}";
                        LastLogin.Text = $"Last login: {ch.LastLogin.ToString()}";
                        Playtime.Text = $"Playtime: {ch.Details.Playtime / 60 / 60} hours";
                        Rank.Text = $"Rank: {ch.Details.Rank}";
                        Money.Text = $"Money: ${ch.Details.Money}";
                        JockerTickets.Text = $"Jocker Tickets: {ch.Details.JokerTickets}";
                        Clan.Text = $"Clan: {ch.Details.Clan}";
                        AppearanceDump.Text = Util.HexDump(ch.Details.Appearance);
                    }
                }
            }
            catch(Exception ex)
            {
                WriteLog(ex.ToString());
            }
        }

        private void Refresh_Click(object sender, EventArgs e)
        {
            //TODO
        }

        private void GetClanInfo_Click(object sender, EventArgs e)
        {
            //TODO
        }

        private void GetMailList_Click(object sender, EventArgs e)
        {
            //TODO
        }

        private void RefreshChallenges_Click(object sender, EventArgs e)
        {
            //TODO
        }

        private void GetFriendsIgnoresList_Click(object sender, EventArgs e)
        {
            //TODO
        }

        private void EnterWorld_Click(object sender, EventArgs e)
        {
            //TODO
        }

        private void RefreshInstances_Click(object sender, EventArgs e)
        {
            //TODO
        }
    }
}