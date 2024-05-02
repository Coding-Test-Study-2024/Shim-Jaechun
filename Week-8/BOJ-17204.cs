using System;

public class BOJ_17204
{
    // 백준 17204번 죽음의 게임

    // dfs 탐색을 통해 도달할 수 없다면 -1
    // 도달할 수 있다면 해당 값 return

    static int n = 0, k = 0, ret = 0;
    static int[] a = new int[151];

    static void Go(int cur, int count)
    {
        // 방문할 수 없는 경우
        if (count > n)
        {
            ret = -1;
            return;
        }

        // 보성이를 찾은 경우
        if (cur == k)
        {
            ret = count;
            return;
        }

        // 다음 부르는 사람으로 재귀
        Go(a[cur], count + 1);
    }

    static void Main(string[] argc)
    {
        string[] temp = Console.ReadLine().Split(" ");

        n = int.Parse(temp[0]);
        k = int.Parse(temp[1]);

        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());

        Go(0, 0);
        Console.WriteLine(ret);
    }
}
