using System;

public class BOJ_17204
{
    // ���� 17204�� ������ ����

    // dfs Ž���� ���� ������ �� ���ٸ� -1
    // ������ �� �ִٸ� �ش� �� return

    static int n = 0, k = 0, ret = 0;
    static int[] a = new int[151];

    static void Go(int cur, int count)
    {
        // �湮�� �� ���� ���
        if (count > n)
        {
            ret = -1;
            return;
        }

        // �����̸� ã�� ���
        if (cur == k)
        {
            ret = count;
            return;
        }

        // ���� �θ��� ������� ���
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
