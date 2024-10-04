// 백준 2210번 숫자판 점프

// 모든 좌표에서 dfs탐색
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int dx[4] = { -1,1, 0,0 };
int dy[4] = { 0,0,1,-1 };

int number[6][6];
set<int> s;

void dfs(int x, int y, int cnt, int num)
{
	if (cnt == 6)
	{
		s.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= 5) continue;
		if (ny < 0 || ny >= 5) continue;

		dfs(nx, ny, cnt + 1, (num * 10) + number[ny][nx]);
	}
}

int main()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cin >> number[y][x];
		}
	}

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			dfs(x, y, 1, number[y][x]);
		}
	}

	cout << s.size() << endl;

	return 0;
}
