// ���� 5567�� ��ȥ��

// ������� �й� : 1
// depth�� 2�� ģ������ Ž��
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

            // ��� ���� : ����� �׷��� (1 <--> 2 == 2 <--> 1)
            if (list[s] == null)
                list[s] = new List<int>();

            list[s].Add(e);

            if (list[e] == null)
                list[e] = new List<int>();

            list[e].Add(s);
        }

        // Set�� �Ҵ�
        // ex)
        //      1 - 2, 2 - 3
        //      1 - 3 �� ��� 3�� �ߺ���.
        SortedSet<int> sSet = new SortedSet<int>();

        // depth1 ģ�� �ݺ�
        for (int i = 0; i < list[1].Count; i++)
        {
            sSet.Add(list[1][i]);

            // depth2 ģ�� �ݺ�
            for (int j = 0; j < list[list[1][i]].Count; j++)
            {
                sSet.Add(list[list[1][i]][j]);
            }
        }

        // -1 : ����� ����
        Console.WriteLine(sSet.Count < 1 ? 0 : sSet.Count - 1);
    }
}