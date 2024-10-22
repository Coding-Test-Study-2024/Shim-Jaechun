using System.Reflection;
using System.Text;

namespace 백준11279번_최대_힙
{
    class Program
    {
        static StringBuilder solution(int n, int[] arr)
        {
            StringBuilder answer = new StringBuilder();

            PriorityQueue<int, int> pq = new PriorityQueue<int, int>();

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] == 0)
                {
                    if (pq.Count == 0)
                        answer.AppendLine("0");
                    else
                        answer.AppendLine($"{pq.Dequeue()}");
                }
                else
                    pq.Enqueue(arr[i], -arr[i]);
            }

            return answer;
        }

        static void Main(string[] argc)
        {
            int n = int.Parse(Console.ReadLine());
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = int.Parse(Console.ReadLine());
            }

            Console.WriteLine(solution(n, arr).ToString());
        }
    }
}