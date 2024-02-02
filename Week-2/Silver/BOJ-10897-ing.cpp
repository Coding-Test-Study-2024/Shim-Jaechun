// 백준 10897번 Inherited disease

// D세대의 정민이 자식을 낳으면 그 자식은 D+1 세대
//
// 세대 별 자식 수 
// 0 = 1
// 1 = 2
// 2 = 6
// 3 =
// if n > 0 
// s(n) = n+1 * s(n-1)

// <실패>
// 2%
// 예제는 모두 돌아감 
// 반례 찾기

#include <iostream>
using namespace std;

typedef long long ll;

const int DIV_NUMBER = 1000000007;
int d, di[101];

void go(int number, int k, int parentCnt)
{
	if (k >= d) return;

	// k의 di[k]번째 자식 찾기
	// s(n) = n+1 * s(n-1)
	if (k == 0)
	{
		cout << 1 << '\n';
		go(1, 1, 1);
	}
	else
	{
		int childCnt = k == 0 ? 1 : parentCnt * (k + 1) % DIV_NUMBER;				// k세대의 총 자식의 수
		int childPerParent = k == 1 ? 1 : childCnt / parentCnt % DIV_NUMBER;		// 총 자식의 수 / 부모의 수 = 각 부모에 속한 자식의 수
		int result = number + childPerParent * (di[k - 1] - 1) + di[k] % DIV_NUMBER;

		cout << result % DIV_NUMBER << '\n';
		go(number + childCnt, k + 1, childCnt);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> d;
	for (int i = 0; i < d; i++)
	{
		cin >> di[i];
	}
	go(0, 0, 0);

	return 0;
}