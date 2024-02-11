// 백준 1992번 쿼드트리

// 분할-정복 시 괄호 여닫기
#include <iostream>
#include <string>
using namespace std;

string answer = "";
int n, a[65][65];

void go(int x, int y, int _n)
{
	int countOne = 0;
	for (int i = y; i < y + _n; i++)
	{
		for (int j = x; j < x + _n; j++)
		{
			if (a[i][j])
				countOne++;
		}
	}

	if (countOne == _n * _n)
	{
		answer += '1';
	}
	else if (countOne == 0)
	{
		answer += '0';
	}
	else
	{
		int div = _n / 2;

		answer += '(';

		go(x, y, div);
		go(x + div, y, div);
		go(x, y + div, div);
		go(x + div, y + div, div);

		answer += ')';
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp = "";
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = temp[j] - '0';
		}
	}
	go(0, 0, n);

	cout << answer << '\n';

	return 0;
}