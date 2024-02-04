// ���� 24460 Ư�����̶� �ް� �;�

// ������ ������ 4���� �������� ��� 3���� �̴´�

// <����>
// �޸� : 6124KB
//   �ð� : 144ms

#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1025][1025];

int go(int y, int x, int n)
{
	if (n == 1)
	{
		return a[y][x];
	}
	int last[4] = { 0, };
	last[0] = go(y, x, n / 2);					// �»� ����
	last[1] = go(y, x + n / 2, n / 2);			// ��� ����
	last[2] = go(y + n / 2, x, n / 2);			// ���� ����
	last[3] = go(y + n / 2, x + n / 2, n / 2);	// ���� ����

	sort(last, last + 4);	// ������ ������
	return last[1];			// �ؿ��� �ι�° ��Ҹ� ����
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	// n == 1
	if (n == 1)
	{
		cout << a[0][0] << '\n';
		return 0;
	}

	cout << go(0, 0, n);

	return 0;
}