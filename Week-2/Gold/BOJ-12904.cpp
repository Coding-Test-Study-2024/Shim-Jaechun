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
//				: 메모리 2024KB
//				:   시간 0ms

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int ret = 0;
string s, t;

// S - A

// T - ABBA

int main()
{
	cin >> s >> t;

	// 문자열의 길이가 서로 같아지면 종료
	while (s.length() < t.length())
	{
		// 행동
		//	1. 뒤에 A삭제
		//	2. B삭제 후 뒤집기
		//  *지금 상태에서 할 수 있는 행동만 실행

		// 뒤의 문자가 같지 않은 경우 빼야함.
		if (s.back() != t.back())
		{
			// T의 뒷부분 문자가 B고
			// S의 뒷부분 문자가 A라면 2번 진행
			if (t.back() == 'B')	
			{
				t.pop_back();
				reverse(t.begin(), t.end());
			}
			// 아니라면 1번 진행
			else 
				t.pop_back();
		}
		// 뒤의 문자가 같은 경우
		else
		{
			// T의 뒷부분 문자가 A라면 1번 진행
			if (t.back() == 'A') 
				t.pop_back();
			// 아니라면 2번 진행
			else
			{
				t.pop_back();
				reverse(t.begin(), t.end());
			}
		}
	}

	ret = s == t ? 1 : 0;
	cout << ret << '\n';
	return 0;
}