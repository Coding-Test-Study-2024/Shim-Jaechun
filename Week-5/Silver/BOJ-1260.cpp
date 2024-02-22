// �׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��϶�.
// ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�,
// �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. 
// ���� ��ȣ�� 1������ N�������̴�.

// --�Է�--
// ù° �ٿ� ������ ���� N(1<=N<=1,000), ������ ���� M(1<=M<=10,000), Ž���� ������ ������ ��ȣ V�� �־�����.
// ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����.
// � �� ���� ���̿� �������� ������ ���� �� �ִ�. �Է����� �־����� ������ ������̴�.

// --���--
// ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�.
// V���� �湮�� ���� ������� ����ϸ� �ȴ�.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

std::vector<int> Node[1001];
bool visited[1001];

void DFS(int start_node)
{
	// ver. ����Լ� ��� 
	visited[start_node] = 1;

	std::cout << start_node << " ";

	for (std::vector<int>::iterator iter = Node[start_node].begin();
		iter < Node[start_node].end();
		iter++)	// ������������ ���ĵ� ������ ù��° ��Ҵ� ���� Ž���� ���.

	{
		if (visited[*iter] != 1)	// �湮�� ��尡 �ƴ� ��� ���
		{
			DFS(*iter);
		}
	}

	// -----------------------

	// ver. ���� ���
	//std::stack<int> neighbor;			// ������ ��带 ���� ���� ����

	//neighbor.push(start_node);			// Ž���� ������ ��� push

	//while (!neighbor.empty())			// ���ÿ� ���� ��Ұ� ���� ������ �ݺ� 
	//{
	//	visited[neighbor.top()] = 1;	// ������ �ֻ��� ��忡 �湮�� üũ

	//	std::cout << neighbor.top() << " ";

	//	int temp = neighbor.top();		// �ֻ��� ��带 ����

	//	neighbor.pop();					// �ֻ��� ��� pop (���ÿ��� ����)

	//	for (auto iter = Node[temp].end() - 1;
	//		iter != Node[temp].begin();
	//		iter--)						// ������ ��� ��带 ������� �ݺ�
	//	{
	//		if (visited[*iter] != 1)	// �湮�� ��尡 �ƴ� ��� push
	//		{
	//			neighbor.push(*iter);	
	//		}
	//	}
	//	if (Node[temp].empty())			// ������ ��尡 ���� ��� �ش��� pop(����)
	//	{
	//		neighbor.pop();
	//	}
	//}
}
void BFS(int start_node)
{
	std::queue<int> neighbor;	// ������ ������ ���� ť

	neighbor.push(start_node);	// ť�� ���� ��� ����

	while (!neighbor.empty())	// ť�� ���� ��Ұ� ���� �� ���� �ݺ�
	{
		if (visited[neighbor.front()] != 1)	// ť�� �� �� ��尡 �湮�� ��尡 �ƴ� ���
		{
			visited[neighbor.front()] = 1;	// �ش� ��� �湮 üũ

			std::cout << neighbor.front() << " ";

			for (std::vector<int>::iterator iter2 = Node[neighbor.front()].begin();
				iter2 != Node[neighbor.front()].end();
				++iter2)					// ������ ��带 ��� ť�� ����
			{
				neighbor.push(*iter2);
			}

			neighbor.pop();					// �ش� ��� pop (����)
		}
		else                                // �湮�� ����� ��� pop (����)
		{
			neighbor.pop();
		}
	}
}

int main()
{

	int N, M, V = 0;

	// �Է� ��
	// ����, ����, ���� ����
	std::cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int start_node = 0;
		int end_node = 0;

		std::cin >> start_node >> end_node;

		// ex) ���� 1, 2
		// {1, 2}, {2, 1}
		Node[start_node].push_back(end_node);
		Node[end_node].push_back(start_node);
	}

	for (int i = 0; i <= N; i++)
	{
		// ���� ���� ���� �������� Ž���ϱ� ���� 
		// ���͸� ������������ ����
		if (!Node[i].empty())
		{
			std::sort(Node[i].begin(), Node[i].end());
		}
	}

	DFS(V);

	std::cout << std::endl;

	// �湮�� ��带 ���� �迭 �ʱ�ȭ
	for (int i = 0; i < sizeof(visited) / sizeof(bool); i++)
	{
		visited[i] = 0;
	}

	BFS(V);

	return 0;
}