// ���α׷��ӽ� ����2 ��ȣ ��ȯ
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// �ùٸ� ��ȣ ���ڿ� üũ
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
    // ���� 4-4 (�� �ڸ� �����ϰ� ������ ���ڿ��� ��ȣ ������ ����� ����)
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

    // �������� - ����/������ ��ȣ ������ ����
    //   �ùٸ� - ������ ���� ¦�� ����

    // 1. �������� ��ȣ ���ڿ� u, v�� �и� (u : ���̻� �и����� ����, v : ���ڿ� ����)
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

    // 2. u�� �ùٸ� ��ȣ ���ڿ��̶�� u���̰� v���
    if (IsRight(u))
        answer += u + solution(v);
    // 3. �ƴ϶�� 4�� ���� ����
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