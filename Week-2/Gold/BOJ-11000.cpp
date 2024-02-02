// 백준 11000번 강의실 배정

// s ~ t 까지의 n개의 수업
// 최소 강의실을 사용해 모든 수업을 가능하게
// 수업이 끝난 직후 다음 수업을 시작할 수 있음.

// <기존 코드>
// 1. 입력받은 배열을 시작시간 기준 오름차로 정렬
// 2. 강의실 최대 개수 200,000 만큼의 배열을 생성하고 ---- a[200001]
//    강의가 끝나는 시점을 기록.                      ---- ex) a[count] = 5   (count는 증설한 강의장 수)
// 3. count만큼의 배열을 돌며 a[j] <= startTime인 
//    지점을 찾아 갱신                                ---- a[j] = endTime
// 4. 갱신할 지점을 찾지 못했다면                     ---- a[count+1] = endTime 
// 5. 최종적으로 count값이 곧 강의실의 개수
// 결과 : 퀵소팅 + O(n^2)으로 시간초과

// <수정>
// S < T 이므로 T > nextS일 경우 무조건 증설해야 함.
// ex) 예제처럼 1 3, 2 4 가 주어져도 굳이 따로 저장할 필요없이
//     우선순위 큐에 입력한다면 3, 4 순서로 빠지고, 3 5는
//     큐의 top이 3과 같기 때문에 pop 후  push 5
// 1. 입력받은 배열을 시작시간 기준 오름차로 정렬
// 2. 강의가 끝나는 시간을 기준으로 오름차 우선순위 큐를 생성
// 3. 정렬된 배열을 순회하며 우선순위 큐에 insert 
// 3-1. 현재 배열 요소의 startTime이 큐의 맨 앞 값(가장 빨리 끝나는 강의)보다 작다면 count++
// 3-2. 크거나 같다면 pop

// 결과
// - 메모리 : 5108KB
// -   시간 : 200ms

// 끝나는 시간을 기준으로 
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;
vector<pair<int, int>> vec;
int n, cnt;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int s = 0, t = 0;
		cin >> s >> t;
		vec.push_back({ s,t });
	}

	// greater s Sort
	sort(vec.begin(), vec.end());

	pq.push(vec[0].second);
	cnt++;
	for (int i = 1; i < vec.size(); i++)
	{
		if (pq.empty()) cnt++;
		else if (pq.top() > vec[i].first) cnt++;
		else pq.pop();

		pq.push(vec[i].second);
	}

	cout << cnt << '\n';
	return 0;
}