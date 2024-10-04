// ���� 1446 ������

// �����ؾ��ϴ� �Ÿ��� �ּڰ�
// �Ϲ�����, ������ �Ұ���

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, d, dp[10001];
vector<vector<int>> vec;

int main()
{
	cin >> n >> d;

	for (int i = 0; i < n; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;

		// ��ӵ����� ���̺��� ������, �������� �ָ� �ִ� ���
		// �������� ����� �ʿ䰡 ���� ��� �̸� ����
		if (s > d || e > d || e - s < t) continue;

		vector<int> temp;

		temp.push_back(s);
		temp.push_back(e);
		temp.push_back(t);

		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());
	for (int i = 1; i <= d; i++)
	{
		// ���� ��ġ���� �Ÿ� ����
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < vec.size(); j++)
		{
			// �������� �������� �� ������ġ�� �ִ� ���
			if (vec[j][1] == i)
				dp[i] = min(dp[i], dp[vec[j][0]] + vec[j][2]);
		}
	}

	cout << dp[d] << '\n';

	return 0;
}