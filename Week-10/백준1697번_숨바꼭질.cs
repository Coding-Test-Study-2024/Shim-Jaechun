using System;
using System.ComponentModel.Design;
using System.Data;
using System.Numerics;
using System.Runtime.CompilerServices;

namespace 백준1697번_숨바꼭질
{
    class Program
    {
        // x+1
        // x-1
        // x*2
        static Func<int, int>[] moveOper = new Func<int, int>[]
        {
            (value) => value + 1,
            (value) => value - 1,
            (value) => value * 2
        };

        // BFS 탐색
        static int solution(int n, int k)
        {
            int[] dp = new int[200001];
            //Array.Fill(dp, -1);
            dp[n] = 1;

            Queue<int> q = new Queue<int>();
            q.Enqueue(n);
            while (q.Count > 0)
            {
                int cur = q.Dequeue();
                for (int i = 0; i < 3; i++)
                {
                    int next = moveOper[i](cur);
                    if (next < 0 || next > 200000) continue;
                    if (dp[next] > 0)
                    {
                        dp[next] = Math.Min(dp[cur] + 1, dp[next]);
                        continue;
                    }
                    dp[next] = dp[cur] + 1;
                    q.Enqueue(next);
                }
            }
            return dp[k] - 1;
        }

        static void Main()
        {
            string[] temp = Console.ReadLine().Split(' ');
            Console.WriteLine(solution(int.Parse(temp[0]), int.Parse(temp[1])));
        }
    }
}