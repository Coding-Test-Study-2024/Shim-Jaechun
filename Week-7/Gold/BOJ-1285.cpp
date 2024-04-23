// ���� 1285�� ���� ������

// �޸��� ���� ���Ͽ� ���� �� �ִ� ������ �ּ� ����
// ���� ������ ��� ����� ���� ���ϰ�
// ������ ��� ����� ������ ���� ������ �� �Ǵ�

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, mn = 987654321, a[21], tempA[21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp = "";
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			if (temp[j] == 'H') continue;

			a[i] |= (1 << j);
		}
	}

	// solve
	for (int i = 0; i < (1 << n) - 1; i++)
	{
		memcpy(tempA, a, sizeof(a));
		// �� ������
		for (int j = 0; j < n; j++)
		{
			// ��Ʈ ����
			if (i & (1 << j))
				tempA[j] = ~tempA[j];
		}

		int sum = 0;
		// �� ������ + ���� ī����
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			for (int k = 0; k < n; k++)
			{
				if (tempA[k] & (1 << j)) cnt++;
			}
			// min(������ ���� ī���ð�, ������ ���� ī���ð�)
			sum += min(cnt, n - cnt);
		}
		mn = min(sum, mn);
	}

	cout << mn << '\n';

	return 0;
}