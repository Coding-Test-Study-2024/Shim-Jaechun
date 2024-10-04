using System;
using System.Text;

public class Solution
{
    public string solution(string s)
    {
        StringBuilder answer = new StringBuilder();
        string[] temp = s.Split(' ');

        foreach (string str in temp)
        {
            // 공백이 연속해서 나온경우 해당 공백을 출력
            if (str.Length < 1)
            {
                answer.Append(" ");
                continue;
            }

            StringBuilder builder = new StringBuilder();

            if (str[0] >= '0' && str[0] <= '9')
                builder.Append(str[0]);
            else
                builder.Append(Char.ToUpper(str[0]));

            // 문자가 하나만 나온경우 예외처리
            if (str.Length > 1)
                builder.Append(str.Substring(1, str.Length - 1).ToLower());


            if (answer.Length > 0)
                answer.Append(" ");

            answer.Append(builder.ToString());
        }

        return answer.ToString();
    }
}