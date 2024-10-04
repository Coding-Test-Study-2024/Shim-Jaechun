// ���� 2212�� ����

// k���� �������� �������� ��
// ���� ���� �Ÿ��� ���� �ּҰ� �� �� �ֵ���

// ������ ���� ���� ������ ��������
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec;
priority_queue<int, vector<int>, less<>> pq;	// �ִ���
int n, k, ret;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	// ���߱��� ��ġ���� �ʾ��� ��� - �ִ� ����
	ret = vec.back() - vec.front();

	for (int i = 0; i < vec.size() - 1; i++)
	{
		// ������ �������� ���� ���
		int dist = vec[i + 1] - vec[i];
		pq.push(dist);
	}

	// �߰��� �κ� k�� �ʿ��̻����� ū ��� ��Ÿ�ӿ���
	if (k >= pq.size())
	{
		cout << 0 << '\n';
		return 0;
	}

	// k-1�� ���߱��� �������� ������ �ѷ� ����.
	while (1 < k--)
	{
		// �ִ� ���� ����
		ret -= pq.top();
		pq.pop();
	}

	cout << ret << '\n';

	return 0;
}

