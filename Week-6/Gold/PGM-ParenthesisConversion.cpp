// 프로그래머스 레벨2 괄호 변환
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// 올바른 괄호 문자열 체크
bool IsRight(string s)
{
    stack<int> st;
    for (char c : s)
    {
        if (c == '(')
            st.push(1);
        else if (st.empty())
            return false;
        else
            st.pop();
    }

    if (st.size())
        return false;
    else
        return true;
}

string Reverse(string s)
{
    // 조건 4-4 (앞 뒤를 제거하고 나머지 문자열의 괄호 방향을 뒤집어서 붙임)
    if (s.length() < 1) return "";

    string ret = "";

    for (int i = 1; i < s.size() - 1; i++)
        ret += s[i] == '(' ? ')' : '(';
    return ret;
}

string solution(string p) {
    string answer = "";

    if (p.size() < 1)
        return answer;

    // 균형잡힌 - 왼쪽/오른쪽 괄호 개수가 같음
    //   올바른 - 개수도 같고 짝도 맞음

    // 1. 균형잡힌 괄호 문자열 u, v로 분리 (u : 더이상 분리하지 못함, v : 빈문자열 가능)
    string u = "", v = "";
    int lc = 0, rc = 0;
    for (char c : p)
    {
        if (!lc && !rc || lc != rc)
        {
            if (c == '(')
                lc++;
            else
                rc++;

            u += c;
        }
        else
            v += c;
    }

    // 2. u가 올바른 괄호 문자열이라면 u붙이고 v재귀
    if (IsRight(u))
        answer += u + solution(v);
    // 3. 아니라면 4번 과정 실행
    else
    {
        answer += '(' + solution(v) + ')';
        answer += Reverse(u);
    }

    return answer;
}

int main()
{
    cout << solution("()))((()") << '\n';

    return 0;
}