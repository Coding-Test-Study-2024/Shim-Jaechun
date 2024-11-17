using System;
namespace 백준11758번_CCW
{
    class Program
    {
        struct Pos
        {
            public int x;
            public int y;
            public Pos(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
        }

        static int CCW(Pos p1, Pos p2, Pos p3)
        {
            Pos v1 = new Pos(p2.x - p1.x, p2.y - p1.y);
            Pos v2 = new Pos(p3.x - p1.x, p3.y - p1.y);

            // 외적 계산
            double cross = ((double)v1.x * v2.y) - ((double)v1.y * v2.x);

            // 반시계 
            if (cross > 0)
                return 1;
            // 시계
            else if (cross < 0)
                return -1;
            // 직선상에 위치
            else
                return 0;
        }

        static void Main(string[] args)
        {
            Pos[] poses = new Pos[3];
            for (int i = 0; i < 3; i++)
            {
                string[] temp = Console.ReadLine().Split(' ');
                poses[i] = new Pos(int.Parse(temp[0]), int.Parse(temp[1]));
            }

            Console.WriteLine(CCW(poses[0], poses[1], poses[2]));
        }
    }
}