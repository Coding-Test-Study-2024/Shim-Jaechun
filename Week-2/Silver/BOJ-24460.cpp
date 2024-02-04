// 백준 24460 특별상이라도 받고 싶어

// 영역의 개수가 4개로 나누어진 경우 3등을 뽑는다

// <성공>
// 메모리 : 6124KB
//   시간 : 144ms

#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1025][1025];

int go(int y, int x, int n)
{
	if (n == 1)
	{
		return a[y][x];
	}
	int last[4] = { 0, };
	last[0] = go(y, x, n / 2);					// 좌상 영역
	last[1] = go(y, x + n / 2, n / 2);			// 우상 영역
	last[2] = go(y + n / 2, x, n / 2);			// 좌하 영역
	last[3] = go(y + n / 2, x + n / 2, n / 2);	// 우하 영역

	sort(last, last + 4);	// 퀵소팅 오름차
	return last[1];			// 밑에서 두번째 요소를 리턴
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	// n == 1
	if (n == 1)
	{
		cout << a[0][0] << '\n';
		return 0;
	}

	cout << go(0, 0, n);

	return 0;
}