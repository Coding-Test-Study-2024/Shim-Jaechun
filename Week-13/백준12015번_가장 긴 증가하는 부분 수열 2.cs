using System;

namespace 백준12015번_가장_긴_증가하는_부분_수열_2
{
    class Program
    {
        static int BinarySearch(int num, List<int> list)
        {
            int l = 0;
            int r = list.Count - 1;

            while (l <= r)
            {
                int mid = (l + r) >> 1;

                if (list[mid] >= num)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            return l;
        }

        static int solution(int n, int[] arr)
        {
            List<int> dp = new List<int>();
            for (int i = 0; i < n; i++)
            {
                if (dp.Count == 0 || dp.Last() < arr[i])
                    dp.Add(arr[i]);
                else
                {
                    int index = BinarySearch(arr[i], dp);
                    dp[index] = arr[i];
                }
            }

            return dp.Count;
        }
        static void Main(string[] argc)
        {
            int n = int.Parse(Console.ReadLine());
            int[] arr = Console.ReadLine().Split(" ").Select(int.Parse).ToArray();

            Console.WriteLine(solution(n, arr));
        }
    }
}