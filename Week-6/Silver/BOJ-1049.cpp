// ���� 1049�� ��Ÿ��

// *���� 6���� ��Ű������ �� ��쵵 ���� �� ����.

// Ǯ��
// : ��Ű���� ���� �� ���� �� �귣��� ������ ���� �� ���� �� �귣�� ã��
// : ���ݸ� �߿���

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
			n % 6 > 0 ? (n / 6 + 1) * mnPack : n / 6 * mnPack,	// ��Ű���θ� ��� ���
											n * mnOne,	// �����θ� ��� ���
							 n / 6 * mnPack + n % 6 * mnOne     // ��Ű�� + ������ ��°��
		}
	);

	cout << ret << '\n';

	return 0;
}