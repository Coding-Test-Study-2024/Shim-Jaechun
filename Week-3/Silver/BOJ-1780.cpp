// ���� 1780�� ������ ����

// ��������, ���
// 3���� ������ ����

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int n, temp[3], answer[3], a[2200][2200];

void go(int x, int y, int _n)
{
	memset(temp, 0, sizeof(temp));
	for (int i = x; i < x + _n; i++)
	{
		for (int j = y; j < y + _n; j++)
		{
			if (a[i][j] == -1)
				temp[0]++;
			else if (a[i][j] == 0)
				temp[1]++;
			else
				temp[2]++;
		}
	}

	bool fnd = false;
	for (int i = 0; i < 3; i++)
	{
		if (temp[i] == _n * _n)
		{
			answer[i]++;
			fnd = true;
			break;
		}
	}

	if (!fnd)
	{
		int div = _n / 3;

		// ��
		go(x, y, div);
		go(x + div, y, div);
		go(x + 2 * div, y, div);
		// ��
		go(x, y + div, div);
		go(x + div, y + div, div);
		go(x + 2 * div, y + div, div);
		// ��
		go(x, y + div * 2, div);
		go(x + div, y + div * 2, div);
		go(x + 2 * div, y + div * 2, div);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	go(0, 0, n);

	for (int i = 0; i < 3; i++)
	{
		cout << answer[i] << '\n';
	}
	return 0;
}