using System;
using System.IO;
using System.Windows.Forms;
using System.Threading.Tasks;
using APBClient;

namespace egoAPBUI
{
    public partial class LoginScreen : Form
    {
        public static HardwareStore hw = null;
        public static APBClient.APBClient client = null;
        public static LoginScreen Instance = null;

        public LoginScreen()
        {
            InitializeComponent();
            Instance = this;
            Username.KeyDown += new KeyEventHandler(TextBoxes_KeyDown);
            Password.KeyDown += new KeyEventHandler(TextBoxes_KeyDown);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;

            if (!Directory.Exists("Packets"))
                Directory.CreateDirectory("Packets");

            if (!Directory.Exists("Appearances"))
                Directory.CreateDirectory("Appearances");

            using (TextReader reader = File.OpenText("hw.yml"))
                hw = new HardwareStore(reader);
        }

        private void Login_Click(object sender, EventArgs e)
        {
            if(Username.Text.Trim().Length < 3 || Password.Text.Trim().Length < 6)
            {
                MessageBox.Show("Provide all required inputs!", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            bool show = true;
            Task.Run(async () =>
            {
                try
                {
                    client = new APBClient.APBClient(Username.Text, Password.Text, hw);
                    await client.Login();
                    Instance.Hide();
                }
                catch
                {
                    MessageBox.Show("Failed to login!", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    show = false;
                }
            }).Wait();

            if(show)
            {
                MainScreen main = new MainScreen();
                main.Show();
            }
        }

        private void About_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Visual application for retrieving and displaying all kinds of game data from APB: Reloaded servers by exposing the Unreal Engine networking for use outside of the game client (APB.exe). Requires the usual login credentials you would use to log in into the game. This does not abuse nor sniff any of your inputted data!", "INFORMATION", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void TextBoxes_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                Login_Click(sender, null);
        }
    }
}