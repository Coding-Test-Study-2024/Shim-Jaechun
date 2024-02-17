// 프로그래머스 레벨2 기능개발

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // 날짜 카운트, 완료된 작업 카운트
    int dayCnt = 0, doneCnt = 0;
    for (int i = 0; i < progresses.size(); i++)
    {
        // 작업의 현재 진행도
        int curPGS = progresses[i] + speeds[i] * dayCnt;

        // 현재 작업이 이미 종료된 경우
        if (curPGS >= 100) doneCnt++;
        // 추가로 작업을 진행해야 하는 경우
        else
        {
            // 이전에 종료된 작업 배포
            if (dayCnt)
                answer.push_back(doneCnt);

            dayCnt += (100 - curPGS) % speeds[i] > 0 ? (100 - curPGS) / speeds[i] + 1 : (100 - curPGS) / speeds[i];
            doneCnt = 1;
        }
    }

    if (doneCnt)
        answer.push_back(doneCnt);

    return answer;
}