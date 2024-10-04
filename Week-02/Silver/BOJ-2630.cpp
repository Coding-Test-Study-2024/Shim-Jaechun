// ���� 2630�� ������ �����

// 1�� : �߸� �Ͼ�� ������ ����
// 2�� : �߸� �Ķ��� ������ ����

// ��������, ��� Ǯ��

// <����>
//	�޸� : 2084KB
//	  �ð� : 4ms


#include <iostream>
#include <math.h>
using namespace std;

int n, answer[2], a[129][129];
int dx[4] = { 1,0,0,1 };

void go(int x, int y, int _n)
{
	int cnt = 0, target = a[y][x];
	for (int i = y; i < y + _n; i++)
	{
		for (int j = x; j < x + _n; j++)
		{
			if (a[i][j] == target) cnt++;
			else
			{
				go(x, y, _n / 2);					// �� ��
				go(x + _n / 2, y, _n / 2);			// �� ��
				go(x + _n / 2, y + _n / 2, _n / 2);	// �� ��
				go(x, y + _n / 2, _n / 2);			// �� ��
				return;
			}
		}
	}

	answer[target]++;
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	go(0, 0, n);
	cout << answer[0] << '\n' << answer[1] << '\n';

	return 0;
}
