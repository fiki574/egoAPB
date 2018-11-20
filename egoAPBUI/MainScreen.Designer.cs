namespace egoAPBUI
{
    partial class MainScreen
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
                components.Dispose();

            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainScreen));
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.MyCharacters = new System.Windows.Forms.TabPage();
            this.RefreshCharacters = new System.Windows.Forms.Button();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.RefreshInstances = new System.Windows.Forms.Button();
            this.EnterWorld = new System.Windows.Forms.Button();
            this.GetFriendsIgnoresList = new System.Windows.Forms.Button();
            this.RefreshChallenges = new System.Windows.Forms.Button();
            this.GetMailList = new System.Windows.Forms.Button();
            this.GetClanInfo = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.AppearanceDump = new System.Windows.Forms.RichTextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.Faction = new System.Windows.Forms.Label();
            this.Gender = new System.Windows.Forms.Label();
            this.Clan = new System.Windows.Forms.Label();
            this.Rank = new System.Windows.Forms.Label();
            this.JockerTickets = new System.Windows.Forms.Label();
            this.Money = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.Threat = new System.Windows.Forms.Label();
            this.SlotNumber = new System.Windows.Forms.Label();
            this.WorldInfo = new System.Windows.Forms.Label();
            this.LastLogin = new System.Windows.Forms.Label();
            this.Playtime = new System.Windows.Forms.Label();
            this.CharactersList = new System.Windows.Forms.ListBox();
            this.MyClan = new System.Windows.Forms.TabPage();
            this.MyMails = new System.Windows.Forms.TabPage();
            this.MyChallenges = new System.Windows.Forms.TabPage();
            this.MyFriends = new System.Windows.Forms.TabPage();
            this.MyIgnores = new System.Windows.Forms.TabPage();
            this.MyInstances = new System.Windows.Forms.TabPage();
            this.MyChats = new System.Windows.Forms.TabPage();
            this.MyMarketplace = new System.Windows.Forms.TabPage();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.SendCommand = new System.Windows.Forms.Button();
            this.Command = new System.Windows.Forms.TextBox();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.tabControl1.SuspendLayout();
            this.MyCharacters.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.MyCharacters);
            this.tabControl1.Controls.Add(this.MyClan);
            this.tabControl1.Controls.Add(this.MyMails);
            this.tabControl1.Controls.Add(this.MyChallenges);
            this.tabControl1.Controls.Add(this.MyFriends);
            this.tabControl1.Controls.Add(this.MyIgnores);
            this.tabControl1.Controls.Add(this.MyInstances);
            this.tabControl1.Controls.Add(this.MyChats);
            this.tabControl1.Controls.Add(this.MyMarketplace);
            this.tabControl1.Location = new System.Drawing.Point(2, 3);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1305, 550);
            this.tabControl1.TabIndex = 0;
            // 
            // MyCharacters
            // 
            this.MyCharacters.Controls.Add(this.RefreshCharacters);
            this.MyCharacters.Controls.Add(this.groupBox5);
            this.MyCharacters.Controls.Add(this.groupBox4);
            this.MyCharacters.Controls.Add(this.groupBox3);
            this.MyCharacters.Controls.Add(this.groupBox2);
            this.MyCharacters.Controls.Add(this.CharactersList);
            this.MyCharacters.Location = new System.Drawing.Point(4, 25);
            this.MyCharacters.Name = "MyCharacters";
            this.MyCharacters.Padding = new System.Windows.Forms.Padding(3);
            this.MyCharacters.Size = new System.Drawing.Size(1297, 521);
            this.MyCharacters.TabIndex = 0;
            this.MyCharacters.Text = "Characters";
            this.MyCharacters.UseVisualStyleBackColor = true;
            // 
            // RefreshCharacters
            // 
            this.RefreshCharacters.Location = new System.Drawing.Point(6, 477);
            this.RefreshCharacters.Name = "RefreshCharacters";
            this.RefreshCharacters.Size = new System.Drawing.Size(120, 38);
            this.RefreshCharacters.TabIndex = 17;
            this.RefreshCharacters.Text = "Refresh!";
            this.RefreshCharacters.UseVisualStyleBackColor = true;
            this.RefreshCharacters.Click += new System.EventHandler(this.Refresh_Click);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.RefreshInstances);
            this.groupBox5.Controls.Add(this.EnterWorld);
            this.groupBox5.Controls.Add(this.GetFriendsIgnoresList);
            this.groupBox5.Controls.Add(this.RefreshChallenges);
            this.groupBox5.Controls.Add(this.GetMailList);
            this.groupBox5.Controls.Add(this.GetClanInfo);
            this.groupBox5.Location = new System.Drawing.Point(136, 395);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(343, 111);
            this.groupBox5.TabIndex = 16;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Actions for selected character (must enter world):";
            // 
            // RefreshInstances
            // 
            this.RefreshInstances.Location = new System.Drawing.Point(175, 81);
            this.RefreshInstances.Name = "RefreshInstances";
            this.RefreshInstances.Size = new System.Drawing.Size(162, 25);
            this.RefreshInstances.TabIndex = 5;
            this.RefreshInstances.Text = "Refresh instances list";
            this.RefreshInstances.UseVisualStyleBackColor = true;
            this.RefreshInstances.Click += new System.EventHandler(this.RefreshInstances_Click);
            // 
            // EnterWorld
            // 
            this.EnterWorld.Location = new System.Drawing.Point(175, 51);
            this.EnterWorld.Name = "EnterWorld";
            this.EnterWorld.Size = new System.Drawing.Size(163, 25);
            this.EnterWorld.TabIndex = 4;
            this.EnterWorld.Text = "Enter world";
            this.EnterWorld.UseVisualStyleBackColor = true;
            this.EnterWorld.Click += new System.EventHandler(this.EnterWorld_Click);
            // 
            // GetFriendsIgnoresList
            // 
            this.GetFriendsIgnoresList.Location = new System.Drawing.Point(175, 21);
            this.GetFriendsIgnoresList.Name = "GetFriendsIgnoresList";
            this.GetFriendsIgnoresList.Size = new System.Drawing.Size(163, 25);
            this.GetFriendsIgnoresList.TabIndex = 3;
            this.GetFriendsIgnoresList.Text = "Get friend+ignore list";
            this.GetFriendsIgnoresList.UseVisualStyleBackColor = true;
            this.GetFriendsIgnoresList.Click += new System.EventHandler(this.GetFriendsIgnoresList_Click);
            // 
            // RefreshChallenges
            // 
            this.RefreshChallenges.Location = new System.Drawing.Point(6, 81);
            this.RefreshChallenges.Name = "RefreshChallenges";
            this.RefreshChallenges.Size = new System.Drawing.Size(163, 25);
            this.RefreshChallenges.TabIndex = 2;
            this.RefreshChallenges.Text = "Refresh challenges";
            this.RefreshChallenges.UseVisualStyleBackColor = true;
            this.RefreshChallenges.Click += new System.EventHandler(this.RefreshChallenges_Click);
            // 
            // GetMailList
            // 
            this.GetMailList.Location = new System.Drawing.Point(6, 51);
            this.GetMailList.Name = "GetMailList";
            this.GetMailList.Size = new System.Drawing.Size(163, 25);
            this.GetMailList.TabIndex = 1;
            this.GetMailList.Text = "Get mails list";
            this.GetMailList.UseVisualStyleBackColor = true;
            this.GetMailList.Click += new System.EventHandler(this.GetMailList_Click);
            // 
            // GetClanInfo
            // 
            this.GetClanInfo.Location = new System.Drawing.Point(6, 21);
            this.GetClanInfo.Name = "GetClanInfo";
            this.GetClanInfo.Size = new System.Drawing.Size(163, 25);
            this.GetClanInfo.TabIndex = 0;
            this.GetClanInfo.Text = "Get clan info";
            this.GetClanInfo.UseVisualStyleBackColor = true;
            this.GetClanInfo.Click += new System.EventHandler(this.GetClanInfo_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.AppearanceDump);
            this.groupBox4.Location = new System.Drawing.Point(499, 6);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(787, 500);
            this.groupBox4.TabIndex = 15;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Appearance dump:";
            // 
            // AppearanceDump
            // 
            this.AppearanceDump.Location = new System.Drawing.Point(6, 21);
            this.AppearanceDump.Name = "AppearanceDump";
            this.AppearanceDump.ReadOnly = true;
            this.AppearanceDump.Size = new System.Drawing.Size(775, 473);
            this.AppearanceDump.TabIndex = 0;
            this.AppearanceDump.Text = "";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.Faction);
            this.groupBox3.Controls.Add(this.Gender);
            this.groupBox3.Controls.Add(this.Clan);
            this.groupBox3.Controls.Add(this.Rank);
            this.groupBox3.Controls.Add(this.JockerTickets);
            this.groupBox3.Controls.Add(this.Money);
            this.groupBox3.Location = new System.Drawing.Point(136, 186);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(343, 203);
            this.groupBox3.TabIndex = 14;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Specific character information:";
            // 
            // Faction
            // 
            this.Faction.AutoSize = true;
            this.Faction.Location = new System.Drawing.Point(6, 27);
            this.Faction.Name = "Faction";
            this.Faction.Size = new System.Drawing.Size(96, 17);
            this.Faction.TabIndex = 2;
            this.Faction.Text = "Faction: None";
            // 
            // Gender
            // 
            this.Gender.AutoSize = true;
            this.Gender.Location = new System.Drawing.Point(5, 54);
            this.Gender.Name = "Gender";
            this.Gender.Size = new System.Drawing.Size(98, 17);
            this.Gender.TabIndex = 4;
            this.Gender.Text = "Gender: None";
            // 
            // Clan
            // 
            this.Clan.AutoSize = true;
            this.Clan.Location = new System.Drawing.Point(6, 164);
            this.Clan.Name = "Clan";
            this.Clan.Size = new System.Drawing.Size(78, 17);
            this.Clan.TabIndex = 12;
            this.Clan.Text = "Clan: None";
            // 
            // Rank
            // 
            this.Rank.AutoSize = true;
            this.Rank.Location = new System.Drawing.Point(6, 83);
            this.Rank.Name = "Rank";
            this.Rank.Size = new System.Drawing.Size(57, 17);
            this.Rank.TabIndex = 9;
            this.Rank.Text = "Rank: 0";
            // 
            // JockerTickets
            // 
            this.JockerTickets.AutoSize = true;
            this.JockerTickets.Location = new System.Drawing.Point(6, 137);
            this.JockerTickets.Name = "JockerTickets";
            this.JockerTickets.Size = new System.Drawing.Size(108, 17);
            this.JockerTickets.TabIndex = 11;
            this.JockerTickets.Text = "Joker Tickets: 0";
            // 
            // Money
            // 
            this.Money.AutoSize = true;
            this.Money.Location = new System.Drawing.Point(6, 110);
            this.Money.Name = "Money";
            this.Money.Size = new System.Drawing.Size(66, 17);
            this.Money.TabIndex = 10;
            this.Money.Text = "Money: 0";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.Threat);
            this.groupBox2.Controls.Add(this.SlotNumber);
            this.groupBox2.Controls.Add(this.WorldInfo);
            this.groupBox2.Controls.Add(this.LastLogin);
            this.groupBox2.Controls.Add(this.Playtime);
            this.groupBox2.Location = new System.Drawing.Point(136, 6);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(343, 174);
            this.groupBox2.TabIndex = 13;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "General character information:";
            // 
            // Threat
            // 
            this.Threat.AutoSize = true;
            this.Threat.Location = new System.Drawing.Point(6, 26);
            this.Threat.Name = "Threat";
            this.Threat.Size = new System.Drawing.Size(142, 17);
            this.Threat.TabIndex = 3;
            this.Threat.Text = "Account threat: None";
            // 
            // SlotNumber
            // 
            this.SlotNumber.AutoSize = true;
            this.SlotNumber.Location = new System.Drawing.Point(5, 54);
            this.SlotNumber.Name = "SlotNumber";
            this.SlotNumber.Size = new System.Drawing.Size(100, 17);
            this.SlotNumber.TabIndex = 1;
            this.SlotNumber.Text = "Slot number: 0";
            // 
            // WorldInfo
            // 
            this.WorldInfo.AutoSize = true;
            this.WorldInfo.Location = new System.Drawing.Point(6, 83);
            this.WorldInfo.Name = "WorldInfo";
            this.WorldInfo.Size = new System.Drawing.Size(87, 17);
            this.WorldInfo.TabIndex = 5;
            this.WorldInfo.Text = "World: None";
            // 
            // LastLogin
            // 
            this.LastLogin.AutoSize = true;
            this.LastLogin.Location = new System.Drawing.Point(6, 111);
            this.LastLogin.Name = "LastLogin";
            this.LastLogin.Size = new System.Drawing.Size(115, 17);
            this.LastLogin.TabIndex = 7;
            this.LastLogin.Text = "Last login: Never";
            // 
            // Playtime
            // 
            this.Playtime.AutoSize = true;
            this.Playtime.Location = new System.Drawing.Point(6, 138);
            this.Playtime.Name = "Playtime";
            this.Playtime.Size = new System.Drawing.Size(77, 17);
            this.Playtime.TabIndex = 8;
            this.Playtime.Text = "Playtime: 0";
            // 
            // CharactersList
            // 
            this.CharactersList.FormattingEnabled = true;
            this.CharactersList.ItemHeight = 16;
            this.CharactersList.Location = new System.Drawing.Point(6, 6);
            this.CharactersList.Name = "CharactersList";
            this.CharactersList.Size = new System.Drawing.Size(120, 468);
            this.CharactersList.TabIndex = 0;
            this.CharactersList.SelectedIndexChanged += new System.EventHandler(this.CharactersList_SelectedIndexChanged);
            // 
            // MyClan
            // 
            this.MyClan.Location = new System.Drawing.Point(4, 25);
            this.MyClan.Name = "MyClan";
            this.MyClan.Padding = new System.Windows.Forms.Padding(3);
            this.MyClan.Size = new System.Drawing.Size(1297, 521);
            this.MyClan.TabIndex = 1;
            this.MyClan.Text = "Clan";
            this.MyClan.UseVisualStyleBackColor = true;
            // 
            // MyMails
            // 
            this.MyMails.Location = new System.Drawing.Point(4, 25);
            this.MyMails.Name = "MyMails";
            this.MyMails.Size = new System.Drawing.Size(1297, 521);
            this.MyMails.TabIndex = 2;
            this.MyMails.Text = "Mails";
            this.MyMails.UseVisualStyleBackColor = true;
            // 
            // MyChallenges
            // 
            this.MyChallenges.Location = new System.Drawing.Point(4, 25);
            this.MyChallenges.Name = "MyChallenges";
            this.MyChallenges.Size = new System.Drawing.Size(1297, 521);
            this.MyChallenges.TabIndex = 8;
            this.MyChallenges.Text = "Challenges";
            this.MyChallenges.UseVisualStyleBackColor = true;
            // 
            // MyFriends
            // 
            this.MyFriends.Location = new System.Drawing.Point(4, 25);
            this.MyFriends.Name = "MyFriends";
            this.MyFriends.Size = new System.Drawing.Size(1297, 521);
            this.MyFriends.TabIndex = 3;
            this.MyFriends.Text = "Friends";
            this.MyFriends.UseVisualStyleBackColor = true;
            // 
            // MyIgnores
            // 
            this.MyIgnores.Location = new System.Drawing.Point(4, 25);
            this.MyIgnores.Name = "MyIgnores";
            this.MyIgnores.Size = new System.Drawing.Size(1297, 521);
            this.MyIgnores.TabIndex = 4;
            this.MyIgnores.Text = "Ignores";
            this.MyIgnores.UseVisualStyleBackColor = true;
            // 
            // MyInstances
            // 
            this.MyInstances.Location = new System.Drawing.Point(4, 25);
            this.MyInstances.Name = "MyInstances";
            this.MyInstances.Size = new System.Drawing.Size(1297, 521);
            this.MyInstances.TabIndex = 5;
            this.MyInstances.Text = "Instances";
            this.MyInstances.UseVisualStyleBackColor = true;
            // 
            // MyChats
            // 
            this.MyChats.Location = new System.Drawing.Point(4, 25);
            this.MyChats.Name = "MyChats";
            this.MyChats.Size = new System.Drawing.Size(1297, 521);
            this.MyChats.TabIndex = 6;
            this.MyChats.Text = "Chats";
            this.MyChats.UseVisualStyleBackColor = true;
            // 
            // MyMarketplace
            // 
            this.MyMarketplace.Location = new System.Drawing.Point(4, 25);
            this.MyMarketplace.Name = "MyMarketplace";
            this.MyMarketplace.Size = new System.Drawing.Size(1297, 521);
            this.MyMarketplace.TabIndex = 7;
            this.MyMarketplace.Text = "Marketplace";
            this.MyMarketplace.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.SendCommand);
            this.groupBox1.Controls.Add(this.Command);
            this.groupBox1.Controls.Add(this.richTextBox1);
            this.groupBox1.Location = new System.Drawing.Point(6, 559);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(1292, 298);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Logs and console";
            // 
            // SendCommand
            // 
            this.SendCommand.Location = new System.Drawing.Point(1101, 252);
            this.SendCommand.Name = "SendCommand";
            this.SendCommand.Size = new System.Drawing.Size(185, 30);
            this.SendCommand.TabIndex = 2;
            this.SendCommand.Text = "Send command!";
            this.SendCommand.UseVisualStyleBackColor = true;
            this.SendCommand.Click += new System.EventHandler(this.SendCommand_Click);
            // 
            // Command
            // 
            this.Command.Location = new System.Drawing.Point(6, 253);
            this.Command.Name = "Command";
            this.Command.Size = new System.Drawing.Size(1089, 22);
            this.Command.TabIndex = 1;
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(6, 21);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.Size = new System.Drawing.Size(1280, 226);
            this.richTextBox1.TabIndex = 0;
            this.richTextBox1.Text = "";
            // 
            // MainScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1310, 874);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.tabControl1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MainScreen";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "External Game Observer for APB: Reloaded - User Interface";
            this.Load += new System.EventHandler(this.MainScreen_Load);
            this.tabControl1.ResumeLayout(false);
            this.MyCharacters.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage MyCharacters;
        private System.Windows.Forms.TabPage MyClan;
        private System.Windows.Forms.TabPage MyMails;
        private System.Windows.Forms.TabPage MyFriends;
        private System.Windows.Forms.TabPage MyIgnores;
        private System.Windows.Forms.TabPage MyInstances;
        private System.Windows.Forms.TabPage MyChats;
        private System.Windows.Forms.TabPage MyMarketplace;
        private System.Windows.Forms.TabPage MyChallenges;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.TextBox Command;
        private System.Windows.Forms.Button SendCommand;
        private System.Windows.Forms.ListBox CharactersList;
        private System.Windows.Forms.Label SlotNumber;
        private System.Windows.Forms.Label Faction;
        private System.Windows.Forms.Label Threat;
        private System.Windows.Forms.Label Gender;
        private System.Windows.Forms.Label WorldInfo;
        private System.Windows.Forms.Label LastLogin;
        private System.Windows.Forms.Label Playtime;
        private System.Windows.Forms.Label Rank;
        private System.Windows.Forms.Label Money;
        private System.Windows.Forms.Label JockerTickets;
        private System.Windows.Forms.Label Clan;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.RichTextBox AppearanceDump;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Button GetClanInfo;
        private System.Windows.Forms.Button GetMailList;
        private System.Windows.Forms.Button RefreshChallenges;
        private System.Windows.Forms.Button EnterWorld;
        private System.Windows.Forms.Button GetFriendsIgnoresList;
        private System.Windows.Forms.Button RefreshCharacters;
        private System.Windows.Forms.Button RefreshInstances;
    }
}