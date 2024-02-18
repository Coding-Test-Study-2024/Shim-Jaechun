// ���� 1715�� ī�� �����ϱ�

// A+B�� ��ĥ �� A+B��ŭ�� �񱳰� �ʿ�
// �� Ƚ���� �ּҷ�

#include <iostream>
#include <queue>
using namespace std;

// �ּ���
priority_queue<int, vector<int>, greater<>> pq;
int n, sum;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		pq.push(temp);
	}

	int temp = 0;
	while (pq.size())
	{
		if (temp)
		{
			int comp = temp + pq.top();
			pq.pop();
			sum += comp;
			// ��ģ ī�� ��ġ�� �ٽ� pq�� �ִ´�
			pq.push(comp);
			temp = 0;
		}
		else
		{
			temp = pq.top();
			pq.pop();
		}
	}

	cout << sum << '\n';
}