using System;
using System.Runtime.Intrinsics;

namespace 백준17386번_선분_교차_1
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
        static Pos GetVector2(Pos p1, Pos p2)
        {
            return new Pos(p2.x - p1.x, p2.y - p1.y);
        }

        // < 0 : ccw
        // > 0 : cw
        // = 0 : 직선
        static int Cross(Pos v1, Pos v2)
        {
            double cross = (double)v1.y * v2.x - (double)v1.x * v2.y;
            if (cross < 0)
                return -1;
            else if (cross > 0)
                return 1;
            else
                return 0;
        }

        static void Main(string[] args)
        {
            string[] temp;
            Pos[] poses = new Pos[4];
            for (int i = 0; i < 2; i++)
            {
                temp = Console.ReadLine().Split(' ');
                poses[i * 2] = new Pos(int.Parse(temp[0]), int.Parse(temp[1]));
                poses[i * 2 + 1] = new Pos(int.Parse(temp[2]), int.Parse(temp[3]));
            }

            // 0_1 선분 기준 외적
            Pos v1 = GetVector2(poses[0], poses[1]);
            Pos v2 = GetVector2(poses[0], poses[2]);
            Pos v3 = GetVector2(poses[0], poses[3]);

            int cross12 = Cross(v1, v2);
            int cross13 = Cross(v1, v3);

            // 직선 상 위치하거나 모두 cw or ccw일 경우 
            // + 세 점이 직선 상에 위치하는 경우는 없음 (cross12 == 0 && cross13 != 0 혹은 그 반대인 경우는 없음)
            if (cross12 == 0 && cross13 == 0 || cross12 == cross13)
                Console.WriteLine(0);
            else
            {
                // 0_2 선분 기준 다시 외적 
                v1 = GetVector2(poses[2], poses[3]);
                v2 = GetVector2(poses[2], poses[0]);
                v3 = GetVector2(poses[2], poses[1]);

                if (Cross(v1, v2) != Cross(v1, v3))
                    Console.WriteLine(1);
                else
                    Console.WriteLine(0);
            }
        }
    }
}