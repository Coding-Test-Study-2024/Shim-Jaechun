// ���� 1446 ������

// �����ؾ��ϴ� �Ÿ��� �ּڰ�
// �Ϲ�����, ������ �Ұ���

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

            // ��ӵ����� ���̺��� ������, �������� �ָ� �ִ� ���
            // �������� ����� �ʿ䰡 ���� ��� �̸� ����
            if (s > d || e > d || e - s < t) continue;

            List<int> temp = new List<int>();

            temp.Add(s);
            temp.Add(e);
            temp.Add(t);

            list.Add(temp);
        }

        // �����غ��� ������ �� �ʿ䰡 ����
        // list.Sort();

        for (int i = 1; i <= d; i++)
        {
            // ���� ��ġ���� �Ÿ� ����
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < list.Count; j++)
            {
                // �������� �������� �� ������ġ�� �ִ� ���
                if (list[j][1] == i)
                    dp[i] = Math.Min(dp[i], dp[list[j][0]] + list[j][2]);
            }
        }

        Console.WriteLine(dp[d]);
    }
}