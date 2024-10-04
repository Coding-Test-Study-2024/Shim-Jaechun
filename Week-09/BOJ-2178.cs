// ���� 2178�� �̷�Ž��

// �ִܰŸ� -> bfs Ž��
using System;

public class BOJ_2178
{
    static int n = 0, m = 0;
    // �� ����, �湮 �迭 ����
    //  - �湮 �迭�� bool�� �ƴ� int �������� ���� ������
    //    Ž�� �� �ִܰŸ��� ��� ������ ����.
    static int[,] map = new int[101, 101], visited = new int[101, 101];

    // �ִܰŸ�, ������ ���ض�

    // ������Ʈ�� ���� �� �ִ� ���� ����
    //  - �����¿� 4����
    static int[] dx = new int[4] { 1, -1, 0, 0 };
    static int[] dy = new int[4] { 0, 0, 1, -1 };

    public struct Pos
    {
        public int x;
        public int y;
        public Pos(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    static void BFS()
    {
        //  ���� ��ġ�� 0,0
        //  ��ǥ������ n-1, m-1
        //  - ��ǥ������ ������������, �ִ� ��θ� ã�ƾ��ϱ⿡ 
        //    BFS Ž���� ���� ��� ��θ� Ž��
        Queue<Pos> q = new Queue<Pos>();
        visited[0, 0] = 1;
        q.Enqueue(new Pos(0, 0));

        while (q.Count > 0)
        {
            Pos temp = q.Dequeue();

            // 4���� Ž��
            for (int i = 0; i < 4; i++)
            {
                // ���� ���� ����
                int nx = dx[i] + temp.x;
                int ny = dy[i] + temp.y;

                // �� ������ ��� ��� continue
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                // ���� ���
                if (map[ny, nx] == 0) continue;

                // �ش� ��ġ�� �̹� �湮�� ���
                if (visited[ny, nx] > 0)
                {
                    // �ش� ��ġ�� �Ҵ�Ǿ��ִ� �����Ÿ��� ���� �����Ÿ�+1 ���� ���� ���� ���� �Ҵ�
                    visited[ny, nx] = Math.Min(visited[ny, nx], visited[temp.y, temp.x] + 1);
                    // �̹� �湮�� ���̱⶧���� ť���� ���� ����  
                    continue;
                }
                else
                    // �����Ÿ� �Ҵ�
                    visited[ny, nx] = visited[temp.y, temp.x] + 1;

                q.Enqueue(new Pos(nx, ny));
            }
        }
    }

    static void Main(string[] argc)
    {
        string[] temp = Console.ReadLine().Split(' ');
        n = int.Parse(temp[0]);
        m = int.Parse(temp[1]);

        for (int i = 0; i < n; i++)
        {
            string str = Console.ReadLine();
            for (int j = 0; j < str.Length; j++)
                map[i, j] = str[j] - '0';
        }

        BFS();

        Console.WriteLine(visited[n - 1, m - 1]);
    }
}