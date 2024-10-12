using System.Runtime.CompilerServices;

namespace 백준5525번_IOIOI
{
    class Program
    {
        // 시작:I 끝:I
        // 스택을 Peek하며 문자가 다를 경우만 Push
        // 배열을 여러번 순회하지 않고 O(N)으로 끝내는게 핵심인듯
        static int solution(int n, int m, string s)
        {
            int answer = 0;
            Stack<char> st = new Stack<char>();

            for (int i = 0; i < s.Length; i++)
            {
                if (st.Count == 0)
                {
                    if (s[i] == 'I')
                        st.Push(s[i]);
                }
                else
                {
                    if (st.Peek() == s[i])
                    {
                        while (st.Count > 0) st.Pop();

                        if (s[i] == 'I')
                            st.Push(s[i]);
                    }
                    else
                    {
                        if (s[i] == 'I' && st.Count == n * 2)
                        {
                            answer++;
                            // 끝에 IO 만 빼기
                            st.Pop();
                            st.Pop();
                        }
                        st.Push(s[i]);
                    }
                }
            }

            return answer;
        }

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int m = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();

            Console.WriteLine(solution(n, m, s));
        }
    }

}