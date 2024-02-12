// 프로그래머스 레벨2 마법의 엘리베이터

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// - 1, 10, 100
// + 1, 10, 100 

// 각 자리의 층 수
//  5 < n : +n
//  5 > n : +(10-n) 다음 자리수 +1
// 5 == n : +n
//    판단 : 다음 자릿수가 5이상인지
//           5 이상이라면 다음 자릿수 +1
//               아니라면 continue

int solution(int storey) {
    int answer = 0;

    int n = storey;
    int mod = 10;
    while (n)
    {
        int temp = n % mod;
        n /= mod;

        if (temp < 5)
            answer += temp;
        else if (temp > 5)
        {
            answer += 10 - temp;
            n += 1;
        }
        else // temp == 5
        {
            answer += temp;

            if (n % mod >= 5)
                n += 1;
        }
    }

    return answer;
}