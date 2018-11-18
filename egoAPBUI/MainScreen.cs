using System;
using System.IO;
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
                    }

                    Worlds = await LoginScreen.client.GetWorlds();
                    WriteLog($"Got {Worlds.Count} worlds");
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
    }
}