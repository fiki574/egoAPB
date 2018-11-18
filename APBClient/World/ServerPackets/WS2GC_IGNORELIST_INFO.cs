using APBClient.Networking;

namespace APBClient.World
{
    public partial class WorldClient
    {
        [PacketHandler(APBOpCode.WS2GC_IGNORELIST_INFO)]
        private class WS2GC_IGNORELIST_INFO : BasePacketHandler<WorldClient>
        {
            public override void HandlePacket(WorldClient client, ServerPacket packet)
            {
                var reader = packet.Reader;

                var ignores = new IgnorelistInfo();
                ignores.TotalIgnores = reader.ReadByte();
                ignores.Ignore = new IgnorelistInfo.Ignored[ignores.TotalIgnores];
                for (int i = 0; i < ignores.TotalIgnores; i++)
                {
                    ignores.Ignore[i] = new IgnorelistInfo.Ignored();
                    ignores.Ignore[i].CharacterID = reader.ReadInt32();
                    ignores.Ignore[i].Name = reader.ReadUnicodeString(Constants.MAX_CHARACTER_NAME);
                }
                client.OnGetIgnorelistSuccess(client, ignores);
            }
        }
    }
}