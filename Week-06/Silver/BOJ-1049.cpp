// 백준 1049번 기타줄

// *낱개 6개가 패키지보다 싼 경우도 있을 수 있음.

// 풀이
// : 패키지로 샀을 때 가장 싼 브랜드와 낱개로 샀을 때 가장 싼 브랜드 찾기
// : 가격만 중요함

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n, m, ret, pack, one, mnPack = INF, mnOne = INF;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> pack >> one;
		mnPack = min(pack, mnPack);
		mnOne = min(one, mnOne);
	}

	ret = min(
		{
			n % 6 > 0 ? (n / 6 + 1) * mnPack : n / 6 * mnPack,	// 패키지로만 사는 경우
											n * mnOne,	// 낱개로만 사는 경우
							 n / 6 * mnPack + n % 6 * mnOne     // 패키지 + 낱개로 사는경우
		}
	);

	cout << ret << '\n';

	return 0;
}