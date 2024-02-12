// ���α׷��ӽ� ����2 ������ ����������

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// - 1, 10, 100
// + 1, 10, 100 

// �� �ڸ��� �� ��
//  5 < n : +n
//  5 > n : +(10-n) ���� �ڸ��� +1
// 5 == n : +n
//    �Ǵ� : ���� �ڸ����� 5�̻�����
//           5 �̻��̶�� ���� �ڸ��� +1
//               �ƴ϶�� continue

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