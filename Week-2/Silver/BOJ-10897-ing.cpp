// ���� 10897�� Inherited disease

// D������ ������ �ڽ��� ������ �� �ڽ��� D+1 ����
//
// ���� �� �ڽ� �� 
// 0 = 1
// 1 = 2
// 2 = 6
// 3 =
// if n > 0 
// s(n) = n+1 * s(n-1)

// <����>
// 2%
// ������ ��� ���ư� 
// �ݷ� ã��

#include <iostream>
using namespace std;

typedef long long ll;

const int DIV_NUMBER = 1000000007;
int d, di[101];

void go(int number, int k, int parentCnt)
{
	if (k >= d) return;

	// k�� di[k]��° �ڽ� ã��
	// s(n) = n+1 * s(n-1)
	if (k == 0)
	{
		cout << 1 << '\n';
		go(1, 1, 1);
	}
	else
	{
		int childCnt = k == 0 ? 1 : parentCnt * (k + 1) % DIV_NUMBER;				// k������ �� �ڽ��� ��
		int childPerParent = k == 1 ? 1 : childCnt / parentCnt % DIV_NUMBER;		// �� �ڽ��� �� / �θ��� �� = �� �θ� ���� �ڽ��� ��
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