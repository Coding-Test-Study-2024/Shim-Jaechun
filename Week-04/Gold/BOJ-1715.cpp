// 백준 1715번 카드 정렬하기

// A+B를 합칠 때 A+B만큼의 비교가 필요
// 비교 횟수를 최소로

#include <iostream>
#include <queue>
using namespace std;

// 최소힙
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
			// 합친 카드 뭉치를 다시 pq에 넣는다
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