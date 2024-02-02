// ���� 12904�� A�� B

// A�� B�� �̷���� ���ڿ� S,T

// dp - s�� �߰�
// Operator
// 1. ���ڿ� �� A �߰�
// 2. ���ڿ� ������ �ڿ� B �߰�

// �׸��� - s�� t�� �ڸ� ���ϸ� �ٸ� ��� ����
// 1. ���ڿ� �� A ����
// 2. ���ڿ� �� B ���� �� ������

// S�� T�� ���� �� �ִ���?

//     dp Ǯ�� - �ð��ʰ�
// �׸��� Ǯ��
//				�޸� : 2024KB
//				  �ð� : 0ms

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int ret = 0;
string s, t;

int main()
{
	cin >> s >> t;
	
	while (s.length() < t.length())
	{
		if (s.back() != t.back())
		{
			if (s.back() == 'A')
			{
				t.pop_back();
				reverse(t.begin(), t.end());
			}
			else t.pop_back();
		}
	}
	ret = s == t ? 1 : 0;
	cout << ret << '\n';
	return 0;
}