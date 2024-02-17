//// 프로그래머스 레벨2 게임 맵 최단거리
//
//// bfs 탐색으로 visited 갱신
//
///**************************************
/// 이전 위치를 {py, px} 라고 했을 때
/// visited[y][x] = visited[py][px] + 1
//***************************************/
//
//#include <vector>
//#include <queue>
//using namespace std;
//
//int visited[101][101];
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//int solution(vector<vector<int>> maps)
//{
//    // bfs탐색
//    queue<pair<int, int>> q;
//    visited[0][0] = 1;
//    q.push({ 0,0 });
//
//    while (q.size())
//    {
//        pair<int, int> temp = q.front();
//        q.pop();
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = temp.second + dx[i];
//            int ny = temp.first + dy[i];
//
//            if (nx == maps[0].size() - 1 && ny == maps.size() - 1)
//                return visited[temp.first][temp.second] + 1;    // 탐색 중 마지막 위치에 도달한 경우 바로 return
//
//            if (nx < 0 || nx >= maps[0].size() || ny < 0 || ny >= maps.size()) continue;
//            if (maps[ny][nx] == 0) continue;
//            if (visited[ny][nx]) continue;
//
//            visited[ny][nx] = visited[temp.first][temp.second] + 1;
//            q.push({ ny,nx });
//        }
//    }
//
//    // 마지막까지 방문하지 못한 경우 return -1
//    return visited[maps.size() - 1][maps[0].size() - 1] == 0 ? -1 : visited[maps.size() - 1][maps[0].size() - 1];
//}

// 프로그래머스 레벨2 조이스틱

// 가장 가까우면서 바꿔야할 알파벳부터 바꾸기

#include <string>
#include <vector>
#include <math.h>
using namespace std;

int VerticalCount(int to)
{
    return min(to, 26 - to);
}

int HorizontalCount(int curIndex, vector<int> v)
{
    int ret = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0) continue;

        int minDist = 0;
        if (curIndex > i)
            minDist = min(curIndex - i, i + v.size() - curIndex);
        else
            minDist = min(i - curIndex, curIndex + v.size() - i);

        ret = min(minDist, ret);
    }
    return ret;
}



int solution(string name) {
    int answer = 0;

    vector<int> vec;
    for (int i = 0; i < name.length(); i++)
        vec.push_back(name[i] - 'A');

    int index = 0;
    while (1)
    {
        index = HorizontalCount(index, vec);
        if (index == -1) break;
        answer += index;
        answer += VerticalCount(index);
    }

    return answer;
}