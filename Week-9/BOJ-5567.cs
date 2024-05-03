// 백준 5567번 결혼식

// 상근이의 학번 : 1
// depth가 2인 친구까지 탐색
using System;

public class BOJ_5567
{
    static void Main(string[] argc)
    {
        int n = 0, m = 0;
        List<int>[] list = new List<int>[10001];
        list[1] = new List<int>();

        n = int.Parse(Console.ReadLine());
        m = int.Parse(Console.ReadLine());

        for (int i = 0; i < m; i++)
        {
            string[] temp = Console.ReadLine().Split(' ');

            int s = int.Parse(temp[0]);
            int e = int.Parse(temp[1]);

            // 노드 연결 : 양방향 그래프 (1 <--> 2 == 2 <--> 1)
            if (list[s] == null)
                list[s] = new List<int>();

            list[s].Add(e);

            if (list[e] == null)
                list[e] = new List<int>();

            list[e].Add(s);
        }

        // Set에 할당
        // ex)
        //      1 - 2, 2 - 3
        //      1 - 3 일 경우 3이 중복됨.
        SortedSet<int> sSet = new SortedSet<int>();

        // depth1 친구 반복
        for (int i = 0; i < list[1].Count; i++)
        {
            sSet.Add(list[1][i]);

            // depth2 친구 반복
            for (int j = 0; j < list[list[1][i]].Count; j++)
            {
                sSet.Add(list[list[1][i]][j]);
            }
        }

        // -1 : 상근이 제거
        Console.WriteLine(sSet.Count < 1 ? 0 : sSet.Count - 1);
    }
}