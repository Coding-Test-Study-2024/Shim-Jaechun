using System;
using System.Text;

public class Solution
{
    public string solution(string s)
    {
        StringBuilder answer = new StringBuilder();

        string[] temp = s.Split(' ');

        int mn = int.MaxValue;
        int mx = int.MinValue;

        foreach (string str in temp)
        {
            mn = Math.Min(int.Parse(str), mn);
            mx = Math.Max(int.Parse(str), mx);
        }

        answer.Append(mn.ToString());
        answer.Append(" ");
        answer.Append(mx.ToString());

        return answer.ToString();
    }
}