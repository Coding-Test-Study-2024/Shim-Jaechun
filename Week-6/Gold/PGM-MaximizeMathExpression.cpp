// 프로그래머스 레벨2 수식 최대화

// + - *의 우선순위
// 절댓값이 가장 큰 값을 만들어야함.

// 4, 9, 16, 17, 26 실패

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

ll solution(string expression) {
	ll answer = 0;

	vector<char> oper;
	vector<ll> num;

	char op[3] = { '-','+','*' };
	int perm[3] = { 0,1,2 };

	// 수, 연산자 할당
	int idx = 0;
	string temp = "";
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			temp += expression[i];
			if (i == expression.size() - 1)
				num.push_back(stoi(temp));
		}
		else
		{
			num.push_back(stoi(temp));
			temp = "";
			oper.push_back(expression[i]);
		}
	}


	// 모든 경우의 수로 판별 : 3! or 2!
	do {
		vector<ll> tempNum = num;
		long long result = 0;

		for (int i = 0; i < 3; i++)
		{
			char cur = op[perm[i]];

			for (int j = 0; j < oper.size(); j++)
			{
				if (oper[j] != cur)
					continue;

				// 연산자 왼쪽 수 찾기
				int lIdx = j;
				while (tempNum[lIdx] == -1 && lIdx > 0)
					lIdx--;

				// 연산자 오른쪽 수 찾기
				int rIdx = j + 1;
				while (tempNum[rIdx] == -1 && rIdx < tempNum.size())
					rIdx++;

				// 결괏값을 왼쪽 인덱스에 저장 후 오른쪽 인덱스의 값을 -1로 할당.
				if (cur == '+')
					tempNum[lIdx] += tempNum[rIdx];
				else if (cur == '-')
					tempNum[lIdx] -= tempNum[rIdx];
				else
					tempNum[lIdx] *= tempNum[rIdx];

				result = tempNum[lIdx];
				tempNum[rIdx] = -1;
			}

			answer = max(answer, abs(result));
		}
	} while (next_permutation(perm, perm + 3));

	return answer;
}