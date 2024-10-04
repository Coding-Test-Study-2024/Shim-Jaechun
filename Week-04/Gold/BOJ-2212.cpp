// 백준 2212번 센서

// k개의 구간으로 나누었을 때
// 구간 사이 거리의 합이 최소가 될 수 있도록

// 간격이 가장 넓은 구간을 기준으로
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec;
priority_queue<int, vector<int>, less<>> pq;	// 최대힙
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

	// 집중국이 설치되지 않았을 경우 - 최대 간격
	ret = vec.back() - vec.front();

	for (int i = 0; i < vec.size() - 1; i++)
	{
		// 인접한 센서와의 간격 계산
		int dist = vec[i + 1] - vec[i];
		pq.push(dist);
	}

	// 추가한 부분 k가 필요이상으로 큰 경우 런타임에러
	if (k >= pq.size())
	{
		cout << 0 << '\n';
		return 0;
	}

	// k-1개 집중국을 기준으로 영역이 둘로 나뉨.
	while (1 < k--)
	{
		// 최대 간격 빼기
		ret -= pq.top();
		pq.pop();
	}

	cout << ret << '\n';

	return 0;
}

