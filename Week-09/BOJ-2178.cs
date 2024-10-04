// 백준 2178번 미로탐색

// 최단거리 -> bfs 탐색
using System;

public class BOJ_2178
{
    static int n = 0, m = 0;
    // 맵 세팅, 방문 배열 세팅
    //  - 방문 배열을 bool이 아닌 int 형식으로 만든 이유는
    //    탐색 중 최단거리를 계속 누적할 것임.
    static int[,] map = new int[101, 101], visited = new int[101, 101];

    // 최단거리, 영역을 구해라

    // 에이전트가 향할 수 있는 방향 설정
    //  - 상하좌우 4방향
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
        //  시작 위치는 0,0
        //  목표지점은 n-1, m-1
        //  - 목표지점이 정해져있지만, 최단 경로를 찾아야하기에 
        //    BFS 탐색을 통해 모든 경로를 탐색
        Queue<Pos> q = new Queue<Pos>();
        visited[0, 0] = 1;
        q.Enqueue(new Pos(0, 0));

        while (q.Count > 0)
        {
            Pos temp = q.Dequeue();

            // 4방향 탐색
            for (int i = 0; i < 4; i++)
            {
                // 다음 방향 설정
                int nx = dx[i] + temp.x;
                int ny = dy[i] + temp.y;

                // 맵 범위를 벗어난 경우 continue
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                // 벽인 경우
                if (map[ny, nx] == 0) continue;

                // 해당 위치를 이미 방문한 경우
                if (visited[ny, nx] > 0)
                {
                    // 해당 위치에 할당되어있는 누적거리와 현재 누적거리+1 값을 비교해 작은 값을 할당
                    visited[ny, nx] = Math.Min(visited[ny, nx], visited[temp.y, temp.x] + 1);
                    // 이미 방문한 곳이기때문에 큐에는 넣지 않음  
                    continue;
                }
                else
                    // 누적거리 할당
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