// 백준 11582번 치킨 TOP N

// n개의 치킨집
// 수치는 무작위
// n/2, n/4 n/8 명의 회원이 차례로 2개의 치킨집을 선택해 정렬
// --> 병합정렬

// 최종적으로 k명이 정렬하는 경우?
// k명이 정렬할 경우 기존 배열은 n/k개로 각각 나뉘어짐.
// n/k개의 배열을 각각 정렬하여 정렬된 배열에 추가

// 조건 
// 4 <= N <= 2^20(1,048,576)

// 시간예상 (2^20)
//  - 병합정렬 : 약 52만번의 분할정렬 + (2^20)/k 만큼의 병합과정 { ? }
//  -  퀵 정렬 : (2^20)/k만큼의 퀵소팅{ O(N) } 

// 결과 
// 
//  - 병합정렬
//		메모리 : 8296KB
//		  시간 : 432ms 
//
//  -   퀵정렬
//		메모리 : 8296KB
//		  시간 : 248ms 


#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int n, k;
vector<int> vec, answer;

void Merge(int start, int mid, int end)
{
	vector<int> temp;

	int lIndex = start;
	int rIndex = mid + 1;
	int index = 0;

	while (lIndex <= mid && rIndex <= end)
	{
		if (vec[lIndex] < vec[rIndex])
			temp.push_back(vec[lIndex++]);
		else
			temp.push_back(vec[rIndex++]);
	}

	while (lIndex <= mid) temp.push_back(vec[lIndex++]);
	while (rIndex <= end) temp.push_back(vec[rIndex++]);

	for (int i = start; i <= end; i++, index++)
		vec[i] = temp[index];
}

void MergeSort(int start, int end)
{
	if (start == end) return;

	int mid = (start + end) / 2;
	MergeSort(start, mid);	 // 머지소팅
	MergeSort(mid + 1, end); //  배열을 둘로 나누어 왼쪽/오른쪽으로 각각 재귀

	// k명이 정렬하는 치킨집들은 각각 k*2개의 치킨집 그룹이다.
	// ex) n=8, k=2
	//		8 = 4 + 4			// 2명의 사람 
	// ex) n=8, k=4
	//		8 = 2 + 2 + 2 + 2	// 4명의 사람
	// ex) n=16, k=2
	//	   16 = 8 + 8
	if (abs(end - start) <= n / k)	// start - end만큼의 치킨집을 정렬해야 할 때 병합
	{
		Merge(start, mid, end);
	}
}

void MySort()
{
	// k명의 사람이 정렬
	for (int i = 0; i < k; i++)
	{
		int index = i * (n / k);		// i번째 사람은 i번 인덱스부터 i+n/k(나뉜 치킨집 개수) 만큼 정렬해야함.
		sort(vec.begin() + index, vec.begin() + index + n / k);	// 퀵소팅
	}
}

int main()
{
	cin.tie(NULL);						// 입출력 연결 해제 (입출력 반복 시 시간 단축)
	ios_base::sync_with_stdio(false);	// stio와 iostream 동기화를 비활성화 (버퍼 공유 해제)

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		vec.push_back(temp);
	}
	cin >> k;

	// 풀이
	//MergeSort(0, n-1);	// 병합정렬 풀이 : 제일 작은 단위까지 분해해야 함.

	MySort();				//   퀵소팅 풀이 : k명이 나누는 그룹에 대해 정렬 후 이어붙이기
							//			     : n/2 > k 일 때 더 효율적이라고 판단함

	// 출력
	for (int i : vec)
	{
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}