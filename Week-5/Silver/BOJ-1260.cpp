// 백준 1260번 DFS와 BFS
// 재풀이

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, m, v;
vector<int> edge[1001];
bool visited[1001];


void dfs(int node)
{
	if (visited[node]) return;

	visited[node] = 1;
	cout << node << ' ';

	for (int i = 0; i < edge[node].size(); i++)
	{
		if (visited[edge[node][i]]) continue;
		dfs(edge[node][i]);
	}
}

void bfs()
{
	queue<int> q;
	q.push(v);
	visited[v] = 1;

	while (q.size())
	{
		int temp = q.front(); q.pop();
		cout << temp << ' ';

		for (int i = 0; i < edge[temp].size(); i++)
		{
			if (visited[edge[temp][i]]) continue;

			visited[edge[temp][i]] = 1;
			q.push(edge[temp][i]);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int s = 0, e = 0;
		cin >> s >> e;
		edge[s].push_back(e);
		edge[e].push_back(s);
	}

	for (int i = 1; i <= n; i++)
		sort(edge[i].begin(), edge[i].end());

	dfs(v);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	bfs();


	return 0;
}