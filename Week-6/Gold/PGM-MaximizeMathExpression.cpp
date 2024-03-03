// ���α׷��ӽ� ����2 ���� �ִ�ȭ

// + - *�� �켱����
// ������ ���� ū ���� ��������.

// 4, 9, 16, 17, 26 ����

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

	// ��, ������ �Ҵ�
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


	// ��� ����� ���� �Ǻ� : 3! or 2!
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

				// ������ ���� �� ã��
				int lIdx = j;
				while (tempNum[lIdx] == -1 && lIdx > 0)
					lIdx--;

				// ������ ������ �� ã��
				int rIdx = j + 1;
				while (tempNum[rIdx] == -1 && rIdx < tempNum.size())
					rIdx++;

				// �ᱣ���� ���� �ε����� ���� �� ������ �ε����� ���� -1�� �Ҵ�.
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