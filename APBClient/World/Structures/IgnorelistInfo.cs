namespace APBClient.World
{
    public class IgnorelistInfo
    {
        public int TotalIgnores;
        public Ignored[] Ignore;

        public class Ignored
        {
            public int CharacterID;
            public string Name;
        }
    }
}