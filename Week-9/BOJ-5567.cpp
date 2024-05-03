// ���� 5567�� ��ȥ��

// ������� �й� : 1
// depth�� 2�� ģ������ Ž��

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> vec[10001];
int n, m, answer;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		vec[s].push_back(e);
		vec[e].push_back(s);
	}

	set<int> fr;

	// depth1 ģ�� �ݺ�
	for (int i = 0; i < vec[1].size(); i++)
	{
		fr.insert(vec[1][i]);
		// depth2 ģ�� �ݺ�
		for (int j = 0; j < vec[vec[1][i]].size(); j++)
		{
			fr.insert(vec[vec[1][i]][j]);
		}
	}

	if (fr.empty())
		cout << 0 << '\n';
	else
		// -1 : ����� ����
		cout << fr.size() - 1 << '\n';

	return 0;
}