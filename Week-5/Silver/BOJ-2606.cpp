// 백준 2606번 바이러스

// 1번 컴퓨터와 인접한 영역 구하기
// 1번부터 dfs 탐색

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, edge, ret;
vector<int> a[101];
bool visited[101];

void dfs(int s)
{
	if (visited[s])
		return;

	visited[s] = 1;
	ret++;

	for (int i = 0; i < a[s].size(); i++)
	{
		if (visited[a[s][i]]) continue;
		dfs(a[s][i]);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> edge;
	// 인접한 노드 할당
	for (int i = 0; i < edge; i++)
	{
		int s = 0, e = 0;
		cin >> s >> e;
		a[s].push_back(e);
		a[e].push_back(s);
	}

	dfs(1);

	// 1번 컴퓨터는 제외
	cout << ret - 1 << '\n';

	return 0;
}