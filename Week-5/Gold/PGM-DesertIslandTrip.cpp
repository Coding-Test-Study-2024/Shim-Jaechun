// 프로그래머스 레벨2 무인도 여행

// 영역의 넓이 구하기 - BFS

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    bool visited[101][101] = { 0, };
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].length(); j++)
        {
            if (maps[i][j] == 'X') continue;
            if (visited[i][j]) continue;

            // bfs탐색
            int ret = maps[i][j] - '0';
            visited[i][j] = 1;
            queue<pair<int, int>> q;
            q.push({ i,j });

            while (q.size())
            {
                pair<int, int> temp = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = temp.second + dx[i];
                    int ny = temp.first + dy[i];

                    if (nx < 0 || nx >= maps[0].length() || ny < 0 || ny >= maps.size()) continue;
                    if (visited[ny][nx]) continue;
                    if (maps[ny][nx] == 'X') continue;

                    ret += maps[ny][nx] - '0';
                    visited[ny][nx] = 1;
                    q.push({ ny, nx });
                }
            }
            answer.push_back(ret);
        }
    }

    if (answer.size())
        sort(answer.begin(), answer.end());
    else
        answer.push_back(-1);

    return answer;
}