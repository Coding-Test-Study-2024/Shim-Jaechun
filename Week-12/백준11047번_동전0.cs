using System.Runtime.InteropServices;

namespace 백준11047번_동전0
{
    class Program
    {
        // 동전 종류 n
        // 가치의 합 k
        // *A[i] 는 A[i-1]의 배수

        // 오답코드 : 이분탐색으로 풀면 틀렸습니다 뜸. 이유를 모르겠음
        //  A[i] <= k 인 최대 i 값 찾기
        static int BinarySearch(int r, int[] arr)
        {
            if (arr.Length <= 1)
                return 0;

            int left = 0;
            int right = arr.Length - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;

                if (arr[mid] >= r)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return right;
        }

        // 비싼 동전부터 사용
        static int solution(int n, int k, int[] arr)
        {
            int ret = 0;
            int maxIndex = n-1;
            while (k > 0)
            {
                if (arr[maxIndex] > k)
                {
                    maxIndex--;
                    continue;
                }

                ret += k / arr[maxIndex];
                k %= arr[maxIndex--];
            }
            return ret;
        }

        static void Main(string[] argc)
        {
            string[] nk = Console.ReadLine().Split(" ");
            int n = int.Parse(nk[0]);
            int k = int.Parse(nk[1]);
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = int.Parse(Console.ReadLine());
            }

            Console.WriteLine($"{solution(n, k, arr)}");
        }
    }
}