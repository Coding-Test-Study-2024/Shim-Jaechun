// ���� 1339�� �ܾ� ����

// ���̰� ���� �� �ܾ� ã��
// ���̰� �� �ܾ�� ���� ���� ������ ���� ã��


// 10
// �ܾ��� �� ������ 
// ex)
//		1. ABB
//		2. BC
//		3. BD
// 		4. BE
//		6. BF
//		7. BG
//		8. BH
//		9. BI
//	   10. BJ
//
// AB
// BA
// CB

// ABC
// BC

// �׸��� -> DP��
// ABABAABA
// ���� - ������ ���


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// �� 8�ڸ���

map<char, vector<int>> m;
int n, ret, num = 9, alpha[26];
string str[10];

bool cmp(pair<char, vector<int>> a, pair<char, vector<int>> b)
{
	for (int i = 8; i >= 0; i--)
	{
		// ���� �ڸ����� ������ ������ ����
		if (a.second[i] == b.second[i])
			continue;
		return a.second[i] > b.second[i];
	}
	// �ǹ̾���
	return a.first < b.first;
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp = "";
		cin >> temp;
		str[i] = temp;
		// �ڸ��� Ȯ���� ���� ���ڿ� ������
		reverse(temp.begin(), temp.end());

		for (int j = 0; j < temp.length(); j++)
		{
			if (m.find(temp[j]) == m.end())
			{
				// �ִ� �ڸ����� 8�ڸ�
				vector<int> tVec(9);
				// �ش� ���ڰ� ������ �ڸ����� ++
				tVec[j]++;
				m.insert({ temp[j],tVec });
			}
			else
			{
				m[temp[j]][j]++;
				if (m[temp[i][j]] > 9)
				{
					m[temp[i][j + 1]]++;
					m[temp[i][j]] = 0;
				}
			}
		}
	}
	vector<pair<char, vector<int>>> vec(m.begin(), m.end());

	// �ڸ��� ���� ����
	sort(vec.begin(), vec.end(), cmp);

	// �켱������ ���� ���ĺ����� 9~0�� �Ҵ�
	for (int i = 0; i < vec.size(); i++)
		m[vec[i].first][0] = num--;

	for (int i = 0; i < n; i++)
	{
		string temp = "";
		for (int j = 0; j < str[i].length(); j++)
		{
			// string to int
			temp += (m[str[i][j]][0] + '0');
		}
		// ��� ���� ���� ��
		ret += stoi(temp);
	}

	cout << ret << '\n';

	return 0;
}