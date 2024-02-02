// 백준 12904번 A와 B

// A와 B로 이루어진 문자열 S,T

// dp - s에 추가
// Operator
// 1. 문자열 뒤 A 추가
// 2. 문자열 뒤집고 뒤에 B 추가

// 그리디 - s와 t의 뒤를 비교하며 다를 경우 삭제
// 1. 문자열 뒤 A 삭제
// 2. 문자열 뒤 B 삭제 후 뒤집기

// S를 T로 만들 수 있는지?

//     dp 풀이 - 시간초과
// 그리디 풀이
//				메모리 : 2024KB
//				  시간 : 0ms

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int ret = 0;
string s, t;

int main()
{
	cin >> s >> t;
	
	while (s.length() < t.length())
	{
		if (s.back() != t.back())
		{
			if (s.back() == 'A')
			{
				t.pop_back();
				reverse(t.begin(), t.end());
			}
			else t.pop_back();
		}
	}
	ret = s == t ? 1 : 0;
	cout << ret << '\n';
	return 0;
}