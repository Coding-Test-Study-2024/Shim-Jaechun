using System;
class Program
{
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
    // 신발끈 공식
    static double GetWidth(Pos[] poses)
    {
        double ret = 0;
        for (int p1 = 0; p1 < poses.Length; p1++)
        {
            // 교차 곱
            int p2 = (p1 + 1) % poses.Length;

            ret += (double)poses[p1].x * poses[p2].y;
            ret -= (double)poses[p1].y * poses[p2].x;
        }
        return Math.Abs(ret) / 2.0;
    }
    static void Main(string[] argc)
    {
        int n = int.Parse(Console.ReadLine());
        Pos[] poses = new Pos[n];
        for (int i = 0; i < n; i++)
        {
            string[] temp = Console.ReadLine().Split(' ');
            poses[i] = new Pos(int.Parse(temp[0]), int.Parse(temp[1]));
        }

        // 소수점 둘째자리에서 반올림
        double answer = Math.Round(GetWidth(poses), 1);

        // 출력은 소수점 첫째자리까지 
        Console.WriteLine(answer.ToString("F1"));
    }
}