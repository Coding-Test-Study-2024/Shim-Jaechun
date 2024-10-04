// ���� 11729�� �ϳ��� ž �̵�����

// �ݺ�
// 1 3 
// 1 2
// 3 2
// 1 3
// 2 1
// 2 3
//  
// 1 3

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> answer;

void go(int t1, int t2, int t3, int count)
{
	if (!count) return;

	// 1�� Ÿ���� ������ 2�� Ÿ����
	go(t1, t3, t2, count - 1);
	answer.push_back({ t1,t3 });
	// 2�� Ÿ���� ������ 3�� Ÿ����
	go(t2, t1, t3, count - 1);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	go(1, 2, 3, n);

	cout << answer.size() << '\n';
	for (pair<int, int> p : answer)
	{
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}