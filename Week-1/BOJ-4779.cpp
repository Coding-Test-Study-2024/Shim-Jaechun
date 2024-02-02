// 백준 4779번 칸토어 집합

// 1. -가 3^n개
// 2. 3등분 후 가운데 문자열을 공백으로 변경.
// 3. 모든 선의 길이가 1일때까지 반복

// 나누고 삭제를 **반복**
// 3^n에서 1이 될때까지 **반복** - 분할 정복(Divide And Conquer)

// 조건 
// 0 <= N <= 12
// 3^12 = 531,441만큼 반복

// 결과
// {첫번째 제출}
// - 메모리 : 4116KB
// -   시간 : 16ms
// 
// {두번째 제출}
// - 메모리 : 4232KB
// -   시간 : 4ms

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <memory.h>
using namespace std;

vector<string> answer;

void DivideAndConquer(int startPos, int n, string& str)
{
	if (n < 1)
	{
		return;
	}
	
	// 3^n 이므로 3번씩 재귀
	// 중앙 지점은 비워주어야 함.
	DivideAndConquer(startPos, n / 3, str);				// 첫번째 지점
	// ex) n = 3	'- -'
	//	   i = 0 = '-'
	//     i = 1 = ' '
	//     i = 2 = '-'
	int midPos = startPos + n / 3;
	for (int i = midPos; i < midPos + n/3; i++)			// 중앙 지점
	{
		str[i] = ' ';
	}
	DivideAndConquer(startPos + n / 3 * 2, n / 3, str);	// 마지막 지점
}

int main()
{
	cin.tie(NULL);						// 입출력 연결 해제 (입출력 반복 시 시간 단축)
	ios_base::sync_with_stdio(false);	// stio와 iostream 동기화를 비활성화 (버퍼 공유 해제)

	int n = -1;
	while (1)
	{
		if ((cin >> n).eof()) break;			// 파일의 끝에서 입력을 멈춘다
		string temp = "";
		temp.resize(pow(3, n));					// 3^n 만큼의 string capacity 할당
		memset(&temp[0], '-', pow(3, n));		// string에 -를 추가
		DivideAndConquer(0, pow(3, n), temp);	// 분할 정복
		answer.push_back(temp);					// 분할 정복의 결과를 answer에 저장
	}

	for (string s : answer)
	{
		cout << s << '\n';
	}

	return 0;
}

// 마무리
//  기존에 작성한 코드는 3^n이라는 점에서 3번에 재귀를 진행했는데
//  중앙 지점은 재귀가 필요없고 단순히 지워주기만하면 된다고 생각하여
//  코드 수정