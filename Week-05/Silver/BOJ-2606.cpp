// ���� 2606�� ���̷���

// 1�� ��ǻ�Ϳ� ������ ���� ���ϱ�
// 1������ dfs Ž��

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
	// ������ ��� �Ҵ�
	for (int i = 0; i < edge; i++)
	{
		int s = 0, e = 0;
		cin >> s >> e;
		a[s].push_back(e);
		a[e].push_back(s);
	}

	dfs(1);

	// 1�� ��ǻ�ʹ� ����
	cout << ret - 1 << '\n';

	return 0;
}