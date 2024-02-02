// ���� 30406�� ��Ÿ ����� ���� ������

// n���� ������ n/2 ����̿��� 2����
// ����(p) : 0<=p<=3
// ������ = ����1xor����2

// �������� �ִ밡 �� �� �ִ� �ͺ���

// xor ���
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

// ����
// �޸� : 2024KB
//   �ð� : 16ms

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