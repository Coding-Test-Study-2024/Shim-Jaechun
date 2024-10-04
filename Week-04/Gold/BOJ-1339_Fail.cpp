// 백준 1339번 단어 수학

// 길이가 가장 긴 단어 찾기
// 길이가 긴 단어에서 가장 많이 등장한 문자 찾기


// 10
// 단어의 총 개수가 
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

// 그리디 -> DP로
// ABABAABA
// 왼쪽 - 오른쪽 계속


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 총 8자릿수

map<char, vector<int>> m;
int n, ret, num = 9, alpha[26];
string str[10];

bool cmp(pair<char, vector<int>> a, pair<char, vector<int>> b)
{
	for (int i = 8; i >= 0; i--)
	{
		// 높은 자릿수가 등장한 순으로 소팅
		if (a.second[i] == b.second[i])
			continue;
		return a.second[i] > b.second[i];
	}
	// 의미없음
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
		// 자릿수 확인을 위해 문자열 뒤집기
		reverse(temp.begin(), temp.end());

		for (int j = 0; j < temp.length(); j++)
		{
			if (m.find(temp[j]) == m.end())
			{
				// 최대 자릿수는 8자리
				vector<int> tVec(9);
				// 해당 문자가 등장한 자릿수를 ++
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

	// 자릿수 기준 소팅
	sort(vec.begin(), vec.end(), cmp);

	// 우선순위가 높은 알파벳부터 9~0을 할당
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
		// 모든 수를 더한 값
		ret += stoi(temp);
	}

	cout << ret << '\n';

	return 0;
}