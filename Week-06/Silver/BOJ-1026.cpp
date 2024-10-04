// 백준 1026번 보물
// 최댓값 * 최솟값

#include <iostream>
#include <algorithm>
using namespace std;

int n, ret, a[51], b[51];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n * 2; i++)
	{
		if (i < n)
			cin >> a[i];
		else
			cin >> b[i - n];
	}

	sort(a, a + n);				// a는 오름차
	sort(b, b + n, greater<>());// b는 내림차

	for (int i = 0; i < n; i++)
		ret += a[i] * b[i];

	cout << ret << '\n';

	return 0;
}

