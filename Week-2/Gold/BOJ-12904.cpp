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
//				: �޸� 2024KB
//				:   �ð� 0ms

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int ret = 0;
string s, t;

// S - A

// T - ABBA

int main()
{
	cin >> s >> t;

	// ���ڿ��� ���̰� ���� �������� ����
	while (s.length() < t.length())
	{
		// �ൿ
		//	1. �ڿ� A����
		//	2. B���� �� ������
		//  *���� ���¿��� �� �� �ִ� �ൿ�� ����

		// ���� ���ڰ� ���� ���� ��� ������.
		if (s.back() != t.back())
		{
			// T�� �޺κ� ���ڰ� B��
			// S�� �޺κ� ���ڰ� A��� 2�� ����
			if (t.back() == 'B')	
			{
				t.pop_back();
				reverse(t.begin(), t.end());
			}
			// �ƴ϶�� 1�� ����
			else 
				t.pop_back();
		}
		// ���� ���ڰ� ���� ���
		else
		{
			// T�� �޺κ� ���ڰ� A��� 1�� ����
			if (t.back() == 'A') 
				t.pop_back();
			// �ƴ϶�� 2�� ����
			else
			{
				t.pop_back();
				reverse(t.begin(), t.end());
			}
		}
	}

	ret = s == t ? 1 : 0;
	cout << ret << '\n';
	return 0;
}