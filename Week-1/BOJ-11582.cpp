// ���� 11582�� ġŲ TOP N

// n���� ġŲ��
// ��ġ�� ������
// n/2, n/4 n/8 ���� ȸ���� ���ʷ� 2���� ġŲ���� ������ ����
// --> ��������

// ���������� k���� �����ϴ� ���?
// k���� ������ ��� ���� �迭�� n/k���� ���� ��������.
// n/k���� �迭�� ���� �����Ͽ� ���ĵ� �迭�� �߰�

// ���� 
// 4 <= N <= 2^20(1,048,576)

// �ð����� (2^20)
//  - �������� : �� 52������ �������� + (2^20)/k ��ŭ�� ���հ��� { ? }
//  -  �� ���� : (2^20)/k��ŭ�� ������{ O(N) } 

// ��� 
// 
//  - ��������
//		�޸� : 8296KB
//		  �ð� : 432ms 
//
//  -   ������
//		�޸� : 8296KB
//		  �ð� : 248ms 


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
	MergeSort(start, mid);	 // ��������
	MergeSort(mid + 1, end); //  �迭�� �ѷ� ������ ����/���������� ���� ���

	// k���� �����ϴ� ġŲ������ ���� k*2���� ġŲ�� �׷��̴�.
	// ex) n=8, k=2
	//		8 = 4 + 4			// 2���� ��� 
	// ex) n=8, k=4
	//		8 = 2 + 2 + 2 + 2	// 4���� ���
	// ex) n=16, k=2
	//	   16 = 8 + 8
	if (abs(end - start) <= n / k)	// start - end��ŭ�� ġŲ���� �����ؾ� �� �� ����
	{
		Merge(start, mid, end);
	}
}

void MySort()
{
	// k���� ����� ����
	for (int i = 0; i < k; i++)
	{
		int index = i * (n / k);		// i��° ����� i�� �ε������� i+n/k(���� ġŲ�� ����) ��ŭ �����ؾ���.
		sort(vec.begin() + index, vec.begin() + index + n / k);	// ������
	}
}

int main()
{
	cin.tie(NULL);						// ����� ���� ���� (����� �ݺ� �� �ð� ����)
	ios_base::sync_with_stdio(false);	// stio�� iostream ����ȭ�� ��Ȱ��ȭ (���� ���� ����)

	// �Է�
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		vec.push_back(temp);
	}
	cin >> k;

	// Ǯ��
	//MergeSort(0, n-1);	// �������� Ǯ�� : ���� ���� �������� �����ؾ� ��.

	MySort();				//   ������ Ǯ�� : k���� ������ �׷쿡 ���� ���� �� �̾���̱�
							//			     : n/2 > k �� �� �� ȿ�����̶�� �Ǵ���

	// ���
	for (int i : vec)
	{
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}