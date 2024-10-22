namespace 백준9375번_패션왕신해빈
{
    class Program
    {
        static void Main(string[] argc)
        {
            int t = int.Parse(Console.ReadLine());
            while (t-- > 0)
            {
                int n = int.Parse(Console.ReadLine());
                Dictionary<string, int> dic = new Dictionary<string, int>();
                for (int i = 0; i < n; i++)
                {
                    string type = Console.ReadLine().Split(" ")[1];
                    if (dic.ContainsKey(type))
                        dic[type]++;
                    else
                        dic[type] = 1;
                }
                int mtp = 1;
                foreach (int value in dic.Values)
                {
                    // 옷을 입지 않는 경우를 포함
                    mtp *= (value + 1);
                }
                // 모든 옷을 입지않는 경우의 수 제거
                Console.WriteLine(mtp - 1);
            }
        }
    }
}