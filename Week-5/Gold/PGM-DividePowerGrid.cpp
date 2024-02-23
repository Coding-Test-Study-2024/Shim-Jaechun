// 프로그래머스 레벨2 전력망 둘로 나누기

// DP : 전선 하나하나를 모두 끊어봄
// BFS : 나뉜 전선에 각각 연결된 영역 구하기

#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

const int INF = 987654321;

int bfs(int start, bool arr[101][101], bool visited[101])
{
    int ret = 1;
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (q.size())
    {
        int n = q.front();
        q.pop();
        for (int i = 0; i < 101; i++)
        {
            if (!arr[n][i]) continue;
            if (visited[i]) continue;

            ret++;
            visited[i] = 1;
            q.push(i);
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {

    int minDif = INF;
    bool link[101][101] = { 0, }, visited[101] = { 0, };

    for (int i = 0; i < wires.size(); i++)
    {
        link[wires[i][0]][wires[i][1]] = 1;
        link[wires[i][1]][wires[i][0]] = 1;
    }

    for (int i = 0; i < wires.size(); i++)
    {
        bool temp[101][101];
        memcpy(temp, link, sizeof(link));

        // 하나 뽑아서 연결 끊기
        temp[wires[i][0]][wires[i][1]] = 0;
        temp[wires[i][1]][wires[i][0]] = 0;

        // 간격 계산
        minDif = min(abs(bfs(wires[i][0], temp, visited) - bfs(wires[i][1], temp, visited)), minDif);
        memset(visited, 0, sizeof(visited));
    }

    return minDif;
}