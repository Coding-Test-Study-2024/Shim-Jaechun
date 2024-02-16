// 프로그래머스 레벨2 게임 맵 최단거리

// bfs 탐색으로 visited 갱신

/**************************************
/ 이전 위치를 {py, px} 라고 했을 때
/ visited[y][x] = visited[py][px] + 1
***************************************/

#include <vector>
#include <queue>
using namespace std;

int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int solution(vector<vector<int>> maps)
{
    // bfs탐색
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({ 0,0 });

    while (q.size())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = temp.second + dx[i];
            int ny = temp.first + dy[i];

            if (nx == maps[0].size() - 1 && ny == maps.size() - 1)
                return visited[temp.first][temp.second] + 1;    // 탐색 중 마지막 위치에 도달한 경우 바로 return

            if (nx < 0 || nx >= maps[0].size() || ny < 0 || ny >= maps.size()) continue;
            if (maps[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[temp.first][temp.second] + 1;
            q.push({ ny,nx });
        }
    }

    // 마지막까지 방문하지 못한 경우 return -1
    return visited[maps.size() - 1][maps[0].size() - 1] == 0 ? -1 : visited[maps.size() - 1][maps[0].size() - 1];
}