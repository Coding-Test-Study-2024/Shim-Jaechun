using System.Data.Common;

namespace 백준9461번_파도반_수열
{
    class Program
    {
        // n > 3
        // dp[n] = dp[n-2] + dp[n-3]

        static long[] dp = new long[101];
        static long solution(int n)
        {
            if (n <= 3)
                return 1;
            else if (dp[n] > 0)
                return dp[n];
            else
            {
                for (int i = 4; i <= n; i++)
                {
                    if (dp[i] > 0) continue;
                    dp[i] = dp[i - 2] + dp[i - 3];
                }
                return dp[n];
            }
        }

        static void Main(string[] argc)
        {
            int t = int.Parse(Console.ReadLine());
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;
            dp[3] = 1;
            while (t-- > 0)
            {
                Console.WriteLine(solution(int.Parse(Console.ReadLine())));
            }
        }
    }
}