// ���� 11000�� ���ǽ� ����

// s ~ t ������ n���� ����
// �ּ� ���ǽ��� ����� ��� ������ �����ϰ�
// ������ ���� ���� ���� ������ ������ �� ����.

// <���� �ڵ�>
// 1. �Է¹��� �迭�� ���۽ð� ���� �������� ����
// 2. ���ǽ� �ִ� ���� 200,000 ��ŭ�� �迭�� �����ϰ� ---- a[200001]
//    ���ǰ� ������ ������ ���.                      ---- ex) a[count] = 5   (count�� ������ ������ ��)
// 3. count��ŭ�� �迭�� ���� a[j] <= startTime�� 
//    ������ ã�� ����                                ---- a[j] = endTime
// 4. ������ ������ ã�� ���ߴٸ�                     ---- a[count+1] = endTime 
// 5. ���������� count���� �� ���ǽ��� ����
// ��� : ������ + O(n^2)���� �ð��ʰ�

// <����>
// S < T �̹Ƿ� T > nextS�� ��� ������ �����ؾ� ��.
// ex) ����ó�� 1 3, 2 4 �� �־����� ���� ���� ������ �ʿ����
//     �켱���� ť�� �Է��Ѵٸ� 3, 4 ������ ������, 3 5��
//     ť�� top�� 3�� ���� ������ pop ��  push 5
// 1. �Է¹��� �迭�� ���۽ð� ���� �������� ����
// 2. ���ǰ� ������ �ð��� �������� ������ �켱���� ť�� ����
// 3. ���ĵ� �迭�� ��ȸ�ϸ� �켱���� ť�� insert 
// 3-1. ���� �迭 ����� startTime�� ť�� �� �� ��(���� ���� ������ ����)���� �۴ٸ� count++
// 3-2. ũ�ų� ���ٸ� pop

// ���
// - �޸� : 5108KB
// -   �ð� : 200ms

// ������ �ð��� �������� 
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