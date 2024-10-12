using System;
using System.Collections.Generic;
using System.Text;
namespace 백준5430번_AC
{
    class Program
    {
        static List<int> solution(string p, int n, int[] arr)
        {
            // 배열의 왼쪽 포인터와 오른쪽 포인터 설정
            // R 입력 시 뒤집음
            List<int> answer = new List<int>();
            int l = 0;
            int r = arr == null ? -1 : arr.Length - 1;
            bool isReverse = false;

            for (int i = 0; i < p.Length; i++)
            {
                if (p[i] == 'R')
                {
                    isReverse = !isReverse;
                }
                else if (p[i] == 'D')
                {
                    if (r < l)
                        return null;

                    if (isReverse)
                        r--;
                    else
                        l++;
                }
            }
            for (int i = l; i <= r; i++)
                answer.Add(arr[i]);

            if (isReverse)
                answer.Reverse();

            return answer;
        }

        static void Main(string[] argc)
        {
            int t = int.Parse(Console.ReadLine());

            StringBuilder answers = new StringBuilder();

            while (t-- > 0)
            {
                string p = Console.ReadLine();
                int n = int.Parse(Console.ReadLine());
                string tempArr = Console.ReadLine().Trim('[', ']');
                // 예외
                // ex) "[]"
                int[] arr =
                    string.IsNullOrEmpty(tempArr) ? null
                    : tempArr.Split(",").Select(int.Parse).ToArray();

                // 출력 값이 없을 때 "[]" 출력 해야함;
                List<int> answer = solution(p, n, arr);
                if (answer != null)
                {
                    answers.Append('[');
                    for (int i = 0; i < answer.Count; i++)
                    {
                        answers.Append(i > 0 ? $",{answer[i]}" : answer[i]);
                    }
                    answers.Append(']');
                    // 마지막 케이스가 아닐경우 줄바꿈 추가
                    if (t > 0) 
                        answers.AppendLine();
                }
                else
                {
                    answers.AppendLine("error");
                }
            }

            Console.WriteLine(answers.ToString());
        }
    }
}