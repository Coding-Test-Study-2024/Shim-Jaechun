// ���� 17204�� ������ ����

// dfs Ž���� ���� ������ �� ���ٸ� -1
// ������ �� �ִٸ� �ش� �� return

#include <iostream>
#include <vector>
using namespace std;

int n, k, ret, a[151];

void go(int cur, int count)
{
	// �湮�� �� ���� ���
	if (count > n)
	{
		ret = -1;
		return;
	}

	// �����̸� ã�� ���
	if (cur == k)
	{
		ret = count;
		return;
	}

	// ���� ������� ���
	go(a[cur], count + 1);
}

int main()
{
	// ��� ����
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	go(0, 0);
	cout << ret << '\n';
	return 0;
}
