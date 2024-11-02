// ����12015�� : ���� �� �����ϴ� �κ� ����2
#include <iostream>
#include <vector>
using namespace std;

int n, arr[1000001], dp[1000001];

int BinarySearch(int l, int r, int num)
{
	int mid = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (dp[mid] >= num)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int cnt = 0;
	dp[0] = arr[0];
	// ���̸� ������� �� ���� �ּ� ������ ����
	for (int i = 1; i < n; i++)
	{
		// ū ���� ���� ���
		if (dp[cnt] < arr[i])
			dp[++cnt] = arr[i];
		// ���� �� üũ
		else
		{
			int index = BinarySearch(0, cnt, arr[i]);
			dp[index] = arr[i];
		}
	}

	cout << cnt + 1 << '\n';

	return 0;
}