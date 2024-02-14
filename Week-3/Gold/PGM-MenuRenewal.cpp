//// ���α׷��ӽ� ����2 �޴� ������
//// �ð��ʰ��ڵ�
//
//#include <string>
//#include <vector>
//#include <iostream>
//#include <math.h>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//// ���ĺ� 26�� 2^26
//// ��Ʈ����ŷ Ǯ�̰���
//int orderBit[21];
//int totalbit, mxOrder;
//
//string BitToAlphabet(int bNum)
//{
//    string ret = "";
//    int cnt = 65; // 'A'
//    while (bNum)
//    {
//        if (bNum % 2 == 1)
//            ret += cnt;
//        cnt++;
//        bNum /= 2;
//    }
//    return ret;
//}
//
//vector<string> solution(vector<string> orders, vector<int> course) {
//    vector<string> answer;
//
//    // string to bit
//    for (int i = 0; i < orders.size(); i++)
//    {
//        for (int j = 0; j < orders[i].length(); j++)
//        {
//            orderBit[i] |= (1 << (orders[i][j] - 'A'));
//        }
//    }
//
//    for (int i = 0; i < course.size(); i++)
//    {
//        int mxCount = 0;
//        map<int, int> m;
//
//        // course[i]�� ��ŭ�� ������ �̾� orderBit�� ��
//        vector<int> temp(26);
//        for (int j = 25; j > 25 - course[i]; j--)
//        {
//            temp[j] = 1;
//        }
//        do
//        {
//            // �������� ���� Bit
//            int curBit = 0;
//            for (int k = 0; k < temp.size(); k++)
//            {
//                if (temp[k] == 1)
//                {
//                    curBit |= (1 << k);
//                }
//            }
//            // map�� �߰�
//            m.insert({ curBit,0 });
//
//            for (int k = 0; k < orders.size(); k++)
//            {
//                // ��������ϴ� �ڽ��丮�� ������ �մ��� �ֹ��� �ֹ��������� Ŭ�� continue
//                if (course[i] > orders[k].length()) continue;
//
//                int getBit = curBit & orderBit[k]; // �ֹ��� �丮 ��Ʈ�� ������ ��Ʈ and ����
//                if (getBit == curBit)
//                {
//                    m[curBit]++;
//                    mxCount = max(m[curBit], mxCount);  // mxCount = �ֹ��� Ƚ���� �ִ�
//                }
//            }
//        } while (next_permutation(temp.begin(), temp.end()));
//
//        if (mxCount < 2) continue;
//
//        for (auto iter = m.begin(); iter != m.end(); iter++)
//        {
//            if (iter->second == mxCount)
//                answer.push_back(BitToAlphabet(iter->first));
//
//        }
//    }
//
//    if (answer.size())
//        sort(answer.begin(), answer.end());
//
//    return answer;
//}

// ����
// �ð��ʰ� - tc.14
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int orderBit[21];
int mxOrder;
set<int> alpha;

string BitToAlphabet(int bNum)
{
    string ret = "";
    int cnt = 65; // 'A'
    while (bNum)
    {
        if (bNum % 2 == 1)
            ret += cnt;
        cnt++;
        bNum /= 2;
    }
    return ret;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // string to bit
    for (int i = 0; i < orders.size(); i++)
    {
        for (int j = 0; j < orders[i].length(); j++)
        {
            orderBit[i] |= (1 << (orders[i][j] - 'A'));
            alpha.insert(orders[i][j] - 'A');
        }
    }

    vector<int> vec(alpha.begin(), alpha.end());

    for (int i = 0; i < course.size(); i++)
    {
        map<int, int> m;
        vector<int> temp(vec.size());
        for (int j = vec.size() - 1; j > vec.size() - course[i] - 1; j--)
        {
            temp[j] = 1;
        }

        int mxCnt = 0;
        do {
            int curBit = 0;
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] == 1)
                    curBit |= (1 << vec[i]);
            }

            m.insert({ curBit, 0 });

            for (int j = 0; j < orders.size(); j++)
            {
                if (orders[j].length() < course[i]) continue;

                int getBit = curBit & orderBit[j];

                if (getBit == curBit)
                {
                    m[curBit]++;
                    mxCnt = max(m[curBit], mxCnt);
                }
            }
        } while (next_permutation(temp.begin(), temp.end()));

        if (mxCnt < 2) continue;

        for (pair<int, int> p : m)
        {
            if (p.second == mxCnt)
                answer.push_back(BitToAlphabet(p.first));
        }
    }

    if (answer.size())
        sort(answer.begin(), answer.end());

    return answer;
}