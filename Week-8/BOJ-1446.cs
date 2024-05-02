// 백준 1446 지름길

// 운전해야하는 거리의 최솟값
// 일방통행, 역주행 불가능

using System;

public class BOJ_1446
{
    static int n = 0, d = 0;
    static int[] dp = new int[10001];
    static List<List<int>> list = new List<List<int>>();

    static void Main(string[] argc)
    {
        string[] nd = Console.ReadLine().Split(' ');
        n = int.Parse(nd[0]);
        d = int.Parse(nd[1]);

        for (int i = 0; i < n; i++)
        {
            int s = 0, e = 0, t = 0;
            string[] tes = Console.ReadLine().Split(' ');
            s = int.Parse(tes[0]);
            e = int.Parse(tes[1]);
            t = int.Parse(tes[2]);

            // 고속도로의 길이보다 시작점, 도착점이 멀리 있는 경우
            // 지름길을 고려할 필요가 없는 경우 미리 제외
            if (s > d || e > d || e - s < t) continue;

            List<int> temp = new List<int>();

            temp.Add(s);
            temp.Add(e);
            temp.Add(t);

            list.Add(temp);
        }

        // 생각해보니 소팅을 할 필요가 없음
        // list.Sort();

        for (int i = 1; i <= d; i++)
        {
            // 현재 위치까지 거리 갱신
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < list.Count; j++)
            {
                // 지름길의 도착지점 중 현재위치가 있는 경우
                if (list[j][1] == i)
                    dp[i] = Math.Min(dp[i], dp[list[j][0]] + list[j][2]);
            }
        }

        Console.WriteLine(dp[d]);
    }
}