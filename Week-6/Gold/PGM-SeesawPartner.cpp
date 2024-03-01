// 프로그래머스 레벨2 시소 짝꿍
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getNum[1001];

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
    for (int i = 0; i < weights.size(); i++)
    {
        if (getNum[weights[i]])
        {
            // 해당 몸무게의 짝꿍들을 이미 구한경우
            getNum[weights[i]]--;   // 중복된 값-- (자기 자신)
            answer += getNum[weights[i]];
            continue;
        }

        // 짝꿍이 될 수 있는 모든 경우의 수
        // 1:1, 2:1, 3:2, 4:3
        int a1 = weights[i];
        int a2 = a1 * 2;
        int a3 = a1 * 3;
        int a4 = a1 * 4;
    
        int getN = 0;
        for (int j = i + 1; j < weights.size(); j++)
        {
            // 1:1
            if (a1 == weights[j]) getN++;
            // 2:1
            if (a2 == weights[j]) getN++;
            // 3:2
            if (a3 == weights[j] * 2) getN++;
            // 4:3
            if (a4 == weights[j] * 3) getN++;
        }
        answer += getN;
        getNum[weights[i]] += getN;
    }

    return answer;
}