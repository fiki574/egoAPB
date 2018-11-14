namespace APBClient.Crypto
{
    internal class XXTEA
    {
        public static void Encrypt(uint[] v, uint[] k, int rounds)
        {
            const uint DELTA = 0x9E3779B9;
            uint sum, y, z, e;
            int n, p;

            sum = 0;
            n = v.Length;
            z = v[n - 1];

            while (rounds-- > 0)
            {
                sum += DELTA;
                e = (sum >> 2) & 3;

                for (p = 0; p < (n - 1); p++)
                {
                    y = v[p + 1];
                    z = v[p] += (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (k[p & 3 ^ e] ^ z);
                }

                y = v[0];
                z = v[n - 1] += (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (k[p & 3 ^ e] ^ z);
            }
        }
    }
}