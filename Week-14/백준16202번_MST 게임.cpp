// ����16202�� MST ����
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m, k, arr[1001];


class UnionFindSplit
{
public:
	UnionFindSplit() {}
	// ��Ʈ��� Ž��
	int Find(int a, vector<int>& root)
	{
		if (root[a] != a)
			root[a] = Find(root[a], root);
		return root[a];
	}
	// �� Ʈ���� ����
	void Union(int a, int b, vector<int>& root, vector<int>& depth)
	{
		int rootA = Find(a, root);
		int rootB = Find(b, root);
		// �̹� ����Ǿ��ִ� ���
		if (rootA == rootB) return;

		// Ʈ�� ���̿� ���� ����
		if (depth[rootA] > depth[rootB])
			root[rootB] = rootA;
		else if (depth[rootA] < depth[rootB])
			root[rootA] = rootB;
		// ���̰� ������ ���
		else
		{
			root[rootB] = rootA;
			depth[rootA]++;	// ���̸� 1 ����
		}
	}
	// ����� Ʈ���� �� Ʈ���� ����
	void Split(int a, int b, vector<int>& root, vector<int>& depth)
	{
		int rootA = Find(a, root);
		int rootB = Find(b, root);

		// �̹� ���ҵ� Ʈ���� ���
		if (rootA != rootB) return;

		root[b] = b;
	}
	// �� Ʈ���� ����Ǿ��ִ��� Ȯ��
	bool IsLinked(int a, int b, vector<int>& root)
	{
		return Find(a, root) == Find(b, root);
	}
};
class Graph
{
private:
	map<int, pair<int, int>> totalEdges;	// �ߺ����� ����
	int nodes;
	int mstValue;		// MST ����ġ ����
	int minValueEdge;	// MST�� �����ϴ� ���� �� ����ġ�� ���� ���� ����
	vector<int> root;	// ��Ʈ ���
	vector<int> depth;	// Ʈ���� ����
	UnionFindSplit ufs;
public:
	Graph(int node) : nodes(node), ufs()
	{
		root.push_back(-1);
		depth.push_back(-1);
		for (int i = 1; i <= node; i++)
		{
			root.push_back(i);	// ���� ��Ʈ��� ����
			depth.push_back(0);	// ���� ����
		}
	}
	void AddEdge(int a, int b, int value)
	{
		// �ߺ��� ������ �־����� ����.
		// ����ġ�� ��������
		totalEdges.insert({ value, {a,b} });
	}
	void RemoveEdge()
	{
		// ���� ������ �ּ� ����Ʈ������ ���� ����ġ�� ���� ���� ���� ����
		if (totalEdges.find(minValueEdge) != totalEdges.end())
		{
			auto& edge = totalEdges[minValueEdge];
			// �ּ� ����Ʈ�� ����ġ ����
			mstValue -= minValueEdge;
			// Ʈ�� ����
			ufs.Split(edge.first, edge.second, root, depth);
			// ���� ����
			totalEdges.erase(minValueEdge);	// ����ġ�θ� Ȯ�� (����ġ�� �ߺ��� ����)
			// MST �ʱ�ȭ
			ClearMST();
		}
	}
	// �ּ� ����Ʈ���� ������ �� ����ġ ��ȯ
	bool MakeMST(int& retValue)
	{
		minValueEdge = -1;	// �ִ� ����ġ�� ������ ���� �ʱ�ȭ
		mstValue = 0;		// MST ��� �ʱ�ȭ
		int edgeCount = 0;	// MST�� �����Ǿ��ٸ� ������ ������ V-1
		for (auto iter = totalEdges.begin(); iter != totalEdges.end(); iter++)
		{
			pair<int, int> edge = (*iter).second;
			int value = (*iter).first;
			// ����Ǿ����� �ʴٸ�
			if (!ufs.IsLinked(edge.first, edge.second, root))
			{
				// ������������ ���ĵ� �������� ó������ ����� ������ �ּ� ����ġ�� ����
				if (minValueEdge == -1)
					minValueEdge = value;
				mstValue += value;
				edgeCount++;
				// ������ ���� ����
				ufs.Union(edge.first, edge.second, root, depth);
			}
		}

		// MST�� ������ �� ���� ���
		if (edgeCount < nodes - 1)
			return false;
		else
		{
			retValue = mstValue;
			return true;
		}
	}
	// �ּҽ���Ʈ�� �ʱ�ȭ
	void ClearMST()
	{
		for (int i = 1; i <= nodes; i++)
		{
			root[i] = i;
			depth[i] = 0;
		}
	}
};

int main()
{
	cin >> n >> m >> k;
	Graph graph(n);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph.AddEdge(a, b, i);
	}

	while (k--)
	{
		int value = 0;
		if (graph.MakeMST(value))
			cout << value << ' ';
		else
		{
			// ���̻� MST�� ������ �� ���� ���
			// ���� ����
			do {
				cout << 0 << ' ';
			} while (k--);

			break;
		}
		graph.RemoveEdge();
	}
	return 0;
}