// ���α׷��ӽ� ����2 ȣ�� ���

// ���� 11000�� ���ǽ� ������ ����
// �׸��� Ǯ��

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

// Ŭ������ ���� �ð� ��ȯ
int GetTime(int time)
{
    int ret = time + 10;
    // 60���� �Ѿ ��� ó��
    if ((ret % 100) / 60) ret += 40;
    
    // ***24�ð��� �Ѿ ���� �߿���������.

    return ret;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int, int>> bTime;
    priority_queue<int, vector<int>, greater<>> pq; // �ּ��� ���

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