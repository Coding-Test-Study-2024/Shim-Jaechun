// 프로그래머스 레벨2 호텔 대실

// 백준 11000번 강의실 배정과 유사
// 그리디 풀이

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

// 클리닝이 끝난 시간 반환
int GetTime(int time)
{
    int ret = time + 10;
    // 60분을 넘어간 경우 처리
    if ((ret % 100) / 60) ret += 40;
    
    // ***24시간을 넘어간 경우는 중요하지않음.

    return ret;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int, int>> bTime;
    priority_queue<int, vector<int>, greater<>> pq; // 최소힙 사용

    for (int i = 0; i < book_time.size(); i++)
    {
        bTime.push_back({
            stoi(book_time[i][0].substr(0,2)) * 100 + stoi(book_time[i][0].substr(3,2)),
            GetTime(stoi(book_time[i][1].substr(0,2)) * 100 + stoi(book_time[i][1].substr(3,2)))
            });
    }

    sort(bTime.begin(), bTime.end());

    for (int i = 0; i < bTime.size(); i++)
    {
        if (pq.empty())
            answer++;
        else if (pq.top() > bTime[i].first)
            answer++;
        else
            pq.pop();

        pq.push(bTime[i].second);
    }

    return answer;
}