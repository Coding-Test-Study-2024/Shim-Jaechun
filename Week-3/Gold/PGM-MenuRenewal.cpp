//// 프로그래머스 레벨2 메뉴 리뉴얼
//// 시간초과코드
//
//#include <string>
//#include <vector>
//#include <iostream>
//#include <math.h>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//// 알파벳 26개 2^26
//// 비트마스킹 풀이가능
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
//        // course[i]개 만큼의 조합을 뽑아 orderBit와 비교
//        vector<int> temp(26);
//        for (int j = 25; j > 25 - course[i]; j--)
//        {
//            temp[j] = 1;
//        }
//        do
//        {
//            // 조합으로 뽑힌 Bit
//            int curBit = 0;
//            for (int k = 0; k < temp.size(); k++)
//            {
//                if (temp[k] == 1)
//                {
//                    curBit |= (1 << k);
//                }
//            }
//            // map에 추가
//            m.insert({ curBit,0 });
//
//            for (int k = 0; k < orders.size(); k++)
//            {
//                // 만들고자하는 코스요리의 개수가 손님이 주문한 주문내역보다 클때 continue
//                if (course[i] > orders[k].length()) continue;
//
//                int getBit = curBit & orderBit[k]; // 주문한 요리 비트와 조합의 비트 and 연산
//                if (getBit == curBit)
//                {
//                    m[curBit]++;
//                    mxCount = max(m[curBit], mxCount);  // mxCount = 주문한 횟수의 최댓값
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

// 최종
// 시간초과 - tc.14
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