// 백준 1003번 피보나치 함수
using System;
public class Program
{
    // 피보나치 : f(n) = f(n-1) + f(n-2)

    // dp[n,2] : n이 주어졌을 때 0과 1이 몇 번 호출되는지
    // dp[0,0] = 1
    // dp[0,1] = 0

    // dp[1,0] = 0
    // dp[1,1] = 1

    // dp[2,0] = 1
    // dp[2,1] = 1

    // dp[3,0] = dp[2,0] + dp[1,0] = 1
    // dp[3,1] = dp[2,1] + dp[1,1] = 2

    // dp[n,0] = dp[n-1,0] + dp[n-2,0]
    // dp[n,1] = dp[n-1,1] + dp[n-2,1]
    static int[,] dp = new int[41, 2];
    static int[] solution(int n)
    {
        int[] answer = new int[2];

        for (int i = 2; i <= n; i++)
        {
            // dp[2,] 부터는 값이 항상 존재
            if (dp[i, 0] != 0) continue;

            dp[i, 0] = dp[i - 2, 0] + dp[i - 1, 0];
            dp[i, 1] = dp[i - 2, 1] + dp[i - 1, 1];
        }
        answer[0] = dp[n, 0];
        answer[1] = dp[n, 1];

        return answer;
    }

    static void Main()
    {
        int t = int.Parse(Console.ReadLine());

        dp[0, 0] = 1;
        dp[0, 1] = 0;
        dp[1, 0] = 0;
        dp[1, 1] = 1;
        while (t-- > 0)
        {
            int n = int.Parse(Console.ReadLine());
            int[] answer = solution(n);
            Console.WriteLine($"{answer[0]} {answer[1]}");
        }
    }
}