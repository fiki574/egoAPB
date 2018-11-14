using APBClient.Networking;
using System.Collections.Generic;

namespace APBClient.Lobby
{
    public partial class LobbyClient
    {
        private class GC2LS_ASK_LOGIN : ClientPacket
        {
            public static Dictionary<int, string> LoginStatuses = new Dictionary<int, string>() {
                { 11002, "LoginFailedInvalidStatus" },
                { 11006, "LoginFailedAgeRestricted" },
                { 10034, "LoginServerConnectCountryBlocked" },
                { 10005, "LoginFailedLoginInProgress" },
                { 10007, "LoginFailedAccountTypeBlocked" },
                { 10008, "LoginFailedAccountBlocked" },
                { 11001, "LoginFailedAccountOrPassword" },
                { 10001, "LoginFailedVersionMismatch" },
                { 8, "LoginServerConnectFailed" },
                { 5, "DatabaseBusy" },
                { -2, "LoginFailedAccountInUse" },
            };

            public GC2LS_ASK_LOGIN(uint puzzleSolution, string email, byte loginType)
            {
                OpCode = (uint)APBOpCode.GC2LS_ASK_LOGIN;

                AllocateData(229);
                Writer.Write(puzzleSolution);
                Writer.Write(0);
                Writer.Write(0);
                Writer.Write(0);
                Writer.Write(0);
                Writer.Write(0);
                Writer.Write(loginType);
                Writer.WriteUnicodeString(email, 130);
                Writer.WriteUnicodeString("", 66);
            }
        }
    }
}