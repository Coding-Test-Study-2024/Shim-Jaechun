// 백준 30406번 산타 춘배의 선물 나누기

// n개의 선물을 n/2 고양이에게 2개씩
// 가격(p) : 0<=p<=3
// 만족도 = 선물1xor선물2

// 만족도가 최대가 될 수 있는 것부터

// xor 결과
// 3
//	0-3
//	1-2
// 2
//	0-2
//	1-3
// 1
//	0-1
//	2-3

// 00
// 01
// 10
// 11

// 성공
// 메모리 : 2024KB
//   시간 : 16ms

#include <iostream>
#include <map>
using namespace std;

const int INF = 987654321;
int n, ret, mn, cnt[6] = { 3,3,2,2,1,1 };
map<int, int> m;
pair<int, int> prioritys[6] = { {0,3}, {1,2}, {0,2},{1,3},{0,1},{2,3} };
int GetSameCount(pair<int, int> p)
{
	mn = INF;
	mn = min(m[p.first], m[p.second]);
	m[p.first] -= mn;
	m[p.second] -= mn;
	return mn;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> n;
	m.insert({ 0,0 });
	m.insert({ 1,0 });
	m.insert({ 2,0 });
	m.insert({ 3,0 });
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		m[temp]++;
	}
	for (int i = 0; i < 6; i++)
	{
		ret += cnt[i] * GetSameCount(prioritys[i]);
	}

	cout << ret << '\n';

	return 0;
}