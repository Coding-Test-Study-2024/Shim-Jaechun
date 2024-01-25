using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

// 백준 1388번 바닥 장식 C# 풀이 
namespace BOJ_1388
{
    class BOJ1388
    {
        // 같은 로직 C# 풀이
        // ______________________________
        // |        |   C#    |    C++  |
        // | 메모리 | 5712KB  |  2028KB |   
        // |   시간 |  64ms   |   64ms  |
        // ------------------------------

        static int n = 0, m = 0, ret = 0;
        static string[] arr;
        static bool[,] visited;

        static void DFS(int y, int x, char c)
        {
            if (x >= m || y >= n) return;
            if (visited[y, x]) return;
            if (arr[y][x] != c) return;

            visited[y, x] = true;

            if (c == '-')
                DFS(y, x + 1, c);
            else // c == '|'
                DFS(y + 1, x, c);
        }

        static void Main(string[] argc)
        {
            string[] temp = Console.ReadLine().Split(' ');
            n = int.Parse(temp[0]);
            m = int.Parse(temp[1]);

            arr = new string[n];
            visited = new bool[n, m];

            for (int i = 0; i < n; i++)
            {
                arr[i] = Console.ReadLine();
            }

            int answer = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!visited[i, j])
                    {
                        answer++;
                        DFS(i, j, arr[i][j]);
                    }
                }
            }
            Console.WriteLine(answer);
        }
    }
}

