// ���� 4779�� ĭ��� ����

// 1. -�� 3^n��
// 2. 3��� �� ��� ���ڿ��� �������� ����.
// 3. ��� ���� ���̰� 1�϶����� �ݺ�

// ������ ������ **�ݺ�**
// 3^n���� 1�� �ɶ����� **�ݺ�** - ���� ����(Divide And Conquer)

// ���� 
// 0 <= N <= 12
// 3^12 = 531,441��ŭ �ݺ�

// ���
// {ù��° ����}
// - �޸� : 4116KB
// -   �ð� : 16ms
// 
// {�ι�° ����}
// - �޸� : 4232KB
// -   �ð� : 4ms

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
	
	// 3^n �̹Ƿ� 3���� ���
	// �߾� ������ ����־�� ��.
	DivideAndConquer(startPos, n / 3, str);				// ù��° ����
	// ex) n = 3	'- -'
	//	   i = 0 = '-'
	//     i = 1 = ' '
	//     i = 2 = '-'
	int midPos = startPos + n / 3;
	for (int i = midPos; i < midPos + n/3; i++)			// �߾� ����
	{
		str[i] = ' ';
	}
	DivideAndConquer(startPos + n / 3 * 2, n / 3, str);	// ������ ����
}

int main()
{
	cin.tie(NULL);						// ����� ���� ���� (����� �ݺ� �� �ð� ����)
	ios_base::sync_with_stdio(false);	// stio�� iostream ����ȭ�� ��Ȱ��ȭ (���� ���� ����)

	int n = -1;
	while (1)
	{
		if ((cin >> n).eof()) break;			// ������ ������ �Է��� �����
		string temp = "";
		temp.resize(pow(3, n));					// 3^n ��ŭ�� string capacity �Ҵ�
		memset(&temp[0], '-', pow(3, n));		// string�� -�� �߰�
		DivideAndConquer(0, pow(3, n), temp);	// ���� ����
		answer.push_back(temp);					// ���� ������ ����� answer�� ����
	}

	for (string s : answer)
	{
		cout << s << '\n';
	}

	return 0;
}

// ������
//  ������ �ۼ��� �ڵ�� 3^n�̶�� ������ 3���� ��͸� �����ߴµ�
//  �߾� ������ ��Ͱ� �ʿ���� �ܼ��� �����ֱ⸸�ϸ� �ȴٰ� �����Ͽ�
//  �ڵ� ����