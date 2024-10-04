// 백준 17204번 죽음의 게임

// dfs 탐색을 통해 도달할 수 없다면 -1
// 도달할 수 있다면 해당 값 return

#include <iostream>
#include <vector>
using namespace std;

int n, k, ret, a[151];

void go(int cur, int count)
{
	// 방문할 수 없는 경우
	if (count > n)
	{
		ret = -1;
		return;
	}

	// 보성이를 찾은 경우
	if (cur == k)
	{
		ret = count;
		return;
	}

	// 다음 사람으로 재귀
	go(a[cur], count + 1);
}

int main()
{
	// 노드 연결
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	go(0, 0);
	cout << ret << '\n';
	return 0;
}
