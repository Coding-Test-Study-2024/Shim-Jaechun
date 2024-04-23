// 백준 1285번 동전 뒤집기

// 뒷면이 위를 향하여 놓일 수 있는 동전의 최소 개수
// 행을 뒤집는 모든 경우의 수를 구하고
// 구해진 모든 경우의 수에서 열을 뒤집을 지 판단

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, mn = 987654321, a[21], tempA[21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp = "";
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			if (temp[j] == 'H') continue;

			a[i] |= (1 << j);
		}
	}

	// solve
	for (int i = 0; i < (1 << n) - 1; i++)
	{
		memcpy(tempA, a, sizeof(a));
		// 행 뒤집기
		for (int j = 0; j < n; j++)
		{
			// 비트 반전
			if (i & (1 << j))
				tempA[j] = ~tempA[j];
		}

		int sum = 0;
		// 열 뒤집기 + 동전 카운팅
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			for (int k = 0; k < n; k++)
			{
				if (tempA[k] & (1 << j)) cnt++;
			}
			// min(뒤집기 전의 카운팅값, 뒤집은 후의 카운팅값)
			sum += min(cnt, n - cnt);
		}
		mn = min(sum, mn);
	}

	cout << mn << '\n';

	return 0;
}