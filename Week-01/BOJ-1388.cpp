// 백준 1388번 바닥 장식

// '-' 모양이 나온 경우는 x축 상 오른쪽으로 한 방향 탐색
// '|' 모양이 나온 경우는 y축 상 아랫쪽으로 한 방향 탐색
// 깊이 우선 탐색인 DFS 알고리즘이 효율적이라고 생각.

// 세로 = n
// 가로 = m
// 1 <= n, m <= 50 (최대 50*50=2500번 탐색)		// 무리 없음
// 시간 복잡도 O(n^2)

// 결과
// 메모리 : 2028KB
//   시간 : 0ms

#include <iostream>
#include <string>
using namespace std;

int n, m, ret;
bool visited[51][51];
string arr[51];

void DFS(int y, int x, char c)
{
	// DFS 기저조건
	if (y >= n || x >= m) return;	// 탐색 범위를 벗어난 경우
	// 0보다 작아지는 경우는 없음 (다음의 증가하는 좌표로 탐색)								

	if (visited[y][x]) return;		// 이미 방문한 경우
	if (arr[y][x] != c) return;		// 바닥 장식이 서로 다른 경우

	// 방문체크
	visited[y][x] = true;

	// 바닥 장식이 '-'일 경우 x축 탐색
	//	   "       '|'일 경우 y축 탐색
	c == '-' ? DFS(y, x + 1, c) : DFS(y + 1, x, c);

	// *추가
	// 입력을 arr의 0부터 받기 때문에 예제 그림을 y축으로 뒤집었다고 볼 수 있음.
	// 때문에 바닥 장식이 '|'인 경우 y-1이 아닌 y+1로 탐색.
}

int main()
{
	cin.tie(NULL);						// 입출력 연결 해제 (입출력 반복 시 시간 단축)
	ios_base::sync_with_stdio(false);	// stio와 iostream 동기화를 비활성화 (버퍼 공유 해제)

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				ret++;	// 문제의 핵심
				// 연결된 바닥 장식이 몇개든 사용한 나무 판자는 1개.
				// ex) '---' = '-' = 1
				//     '|'
				//	   '|' = '|' = 1
				//	   '|'
				DFS(i, j, arr[i][j]);
			}
		}
	}

	cout << ret << '\n';

	return 0;
}
