// 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하라.
// 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
// 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
// 정점 번호는 1번부터 N번까지이다.

// --입력--
// 첫째 줄에 정점의 개수 N(1<=N<=1,000), 간선의 개수 M(1<=M<=10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
// 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
// 어떤 두 정점 사이에 여러개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

// --출력--
// 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다.
// V부터 방문된 점을 순서대로 출력하면 된다.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

std::vector<int> Node[1001];
bool visited[1001];

void DFS(int start_node)
{
	// ver. 재귀함수 사용 
	visited[start_node] = 1;

	std::cout << start_node << " ";

	for (std::vector<int>::iterator iter = Node[start_node].begin();
		iter < Node[start_node].end();
		iter++)	// 오름차순으로 정렬된 벡터의 첫번째 요소는 다음 탐색할 노드.

	{
		if (visited[*iter] != 1)	// 방문한 노드가 아닐 경우 재귀
		{
			DFS(*iter);
		}
	}

	// -----------------------

	// ver. 스택 사용
	//std::stack<int> neighbor;			// 인접한 노드를 담을 스택 생성

	//neighbor.push(start_node);			// 탐색을 시작할 노드 push

	//while (!neighbor.empty())			// 스택에 남은 요소가 없을 때까지 반복 
	//{
	//	visited[neighbor.top()] = 1;	// 스택의 최상위 노드에 방문을 체크

	//	std::cout << neighbor.top() << " ";

	//	int temp = neighbor.top();		// 최상위 노드를 복사

	//	neighbor.pop();					// 최상위 노드 pop (스택에서 삭제)

	//	for (auto iter = Node[temp].end() - 1;
	//		iter != Node[temp].begin();
	//		iter--)						// 인접한 모든 노드를 대상으로 반복
	//	{
	//		if (visited[*iter] != 1)	// 방문한 노드가 아닐 경우 push
	//		{
	//			neighbor.push(*iter);	
	//		}
	//	}
	//	if (Node[temp].empty())			// 인접한 노드가 없을 경우 해당노드 pop(삭제)
	//	{
	//		neighbor.pop();
	//	}
	//}
}
void BFS(int start_node)
{
	std::queue<int> neighbor;	// 인접한 노드들을 담을 큐

	neighbor.push(start_node);	// 큐에 시작 노드 삽입

	while (!neighbor.empty())	// 큐에 남은 요소가 없을 때 까지 반복
	{
		if (visited[neighbor.front()] != 1)	// 큐의 맨 앞 노드가 방문한 노드가 아닐 경우
		{
			visited[neighbor.front()] = 1;	// 해당 노드 방문 체크

			std::cout << neighbor.front() << " ";

			for (std::vector<int>::iterator iter2 = Node[neighbor.front()].begin();
				iter2 != Node[neighbor.front()].end();
				++iter2)					// 인접한 노드를 모두 큐에 삽입
			{
				neighbor.push(*iter2);
			}

			neighbor.pop();					// 해당 노드 pop (삭제)
		}
		else                                // 방문한 노드일 경우 pop (삭제)
		{
			neighbor.pop();
		}
	}
}

int main()
{

	int N, M, V = 0;

	// 입력 순
	// 정점, 간선, 시작 정점
	std::cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int start_node = 0;
		int end_node = 0;

		std::cin >> start_node >> end_node;

		// ex) 간선 1, 2
		// {1, 2}, {2, 1}
		Node[start_node].push_back(end_node);
		Node[end_node].push_back(start_node);
	}

	for (int i = 0; i <= N; i++)
	{
		// 낮은 수를 가진 정점부터 탐색하기 위해 
		// 벡터를 오름차순으로 정렬
		if (!Node[i].empty())
		{
			std::sort(Node[i].begin(), Node[i].end());
		}
	}

	DFS(V);

	std::cout << std::endl;

	// 방문한 노드를 담은 배열 초기화
	for (int i = 0; i < sizeof(visited) / sizeof(bool); i++)
	{
		visited[i] = 0;
	}

	BFS(V);

	return 0;
}