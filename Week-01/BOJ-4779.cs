using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Cantor
{
    static void DivideAndConquer(StringBuilder stbd, int pos, int n)
    {
        if (n == 0) return;

        DivideAndConquer(stbd, pos, n / 3);
        for (int i = pos + n / 3; i < pos + n / 3 * 2; i++)
        {
            stbd[i] = ' ';
        }
        DivideAndConquer(stbd, pos + n / 3 * 2, n / 3);
    }

    static void Main(string[] argc)
    {
        string str = " ";
        while (!string.IsNullOrEmpty(str))
        {
            str = Console.ReadLine();
            if (string.IsNullOrEmpty(str)) return;
            int n = int.Parse(str);
            int powN = (int)Math.Pow(3, n);
            StringBuilder stbd = new StringBuilder();
            for (int i = 0; i < powN; i++)
            {
                stbd.Append("-");
            }
            DivideAndConquer(stbd, 0, powN);
            Console.WriteLine(stbd);
        }
    }
}