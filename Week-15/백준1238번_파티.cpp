// ����1238�� ��Ƽ
// ���ͽ�Ʈ��
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
int n, m, x;
struct comparer {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.first < a.second;
	}
};
vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& edge)
{
	vector<int> visited(n + 1, INF);
	visited[start] = 0;

	// ���� ��忡�� ���� ����� ������ 
	// value, node
	priority_queue<pair<int, int>, vector<pair<int, int>>, comparer> pq;
	pq.push({ visited[start], start });

	while (pq.size())
	{
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		// �ִܰŸ��� ���ŵ� ��ζ�� ����
		if (curDist > visited[curNode])
			continue;

		for (int i = 0; i < edge[curNode].size(); i++)
		{
			int next = edge[curNode][i].first;
			int value = edge[curNode][i].second;

			if (visited[next] <= curDist + value)
				continue;

			visited[next] = curDist + value;
			pq.push({ visited[next], next });
		}
	}

	return visited;
}

int main()
{
	cin >> n >> m >> x;
	vector<vector<pair<int, int>>> edges(n + 1);
	// Ÿ ���鿡�� Ư�� �������� �ִܰŸ��� ���ϱ� ����
	vector<vector<pair<int, int>>> reverseEdges(n + 1);
	for (int i = 0; i < m; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		edges[s].push_back({ e,t });
		reverseEdges[e].push_back({ s,t });
	}

	int distToParty = 0;
	int ret = 0;
	// ��Ƽ���� ������ �Ÿ�
	vector<int> toHomes = dijkstra(x, edges);
	// �� ������ ��Ƽ������ �Ÿ�
	vector<int> toParty = dijkstra(x, reverseEdges);
	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;

		// �Ÿ� ��
		int sum = toHomes[i] + toParty[i];
		if (ret < sum)
			ret = sum;
	}

	cout << ret << '\n';

	return 0;
}