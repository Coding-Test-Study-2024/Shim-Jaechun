// 프로그래머스 레벨2 메뉴 리뉴얼
// 시간초과 - tc.14

//#include <string>
//#include <vector>
//#include <iostream>
//#include <math.h>
//#include <map>
//#include <set>
//#include <algorithm>
//using namespace std;
//
//int orderBit[21];
//int mxOrder;
//set<int> alpha;
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
//            alpha.insert(orders[i][j] - 'A');
//        }
//    }
//
//    vector<int> vec(alpha.begin(), alpha.end());
//
//    for (int i = 0; i < course.size(); i++)
//    {
//        map<int, int> m;
//        vector<int> temp(vec.size());
//        for (int j = vec.size() - 1; j > vec.size() - course[i] - 1; j--)
//        {
//            temp[j] = 1;
//        }
//
//        int mxCnt = 0;
//        do {
//            int curBit = 0;
//            for (int i = 0; i < temp.size(); i++)
//            {
//                if (temp[i] == 1)
//                    curBit |= (1 << vec[i]);
//            }
//
//            m.insert({ curBit, 0 });
//
//            for (int j = 0; j < orders.size(); j++)
//            {
//                if (orders[j].length() < course[i]) continue;
//
//                int getBit = curBit & orderBit[j];
//
//                if (getBit == curBit)
//                {
//                    m[curBit]++;
//                    mxCnt = max(m[curBit], mxCnt);
//                }
//            }
//        } while (next_permutation(temp.begin(), temp.end()));
//
//        if (mxCnt < 2) continue;
//
//        for (pair<int, int> p : m)
//        {
//            if (p.second == mxCnt)
//                answer.push_back(BitToAlphabet(p.first));
//        }
//    }
//
//    if (answer.size())
//        sort(answer.begin(), answer.end());
//
//    return answer;
//}

// 프로그래머스 레벨2 통과코드
// 비트마스킹 안씀 더 어려움
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < course.size(); i++)
    {
        map<string, int> m;
        int mxOrder = 0;    // 가장 많이 주문받은 메뉴만 뽑기

        for (int j = 0; j < orders.size(); j++)
        {
            if (orders[j].length() < course[i]) continue;

            // 조합을 돌리기 위한 벡터
            // 0 : 안뽑음
            // 1 : 뽑음
            vector<int> comb(orders[j].length() - course[i]);

            // 오름차순으로 정렬된 벡터에 한해 next_permutation 사용 가능
            for (int k = 0; k < course[i]; k++)
                comb.push_back(1);

            do {
                string temp = "";
                for (int k = 0; k < comb.size(); k++)
                {
                    if (comb[k] == 1)
                        temp += orders[j][k];
                }

                // AB와 BA 조합이 나올 수 있기 때문에 소팅
                sort(temp.begin(), temp.end());

                if (m.find(temp) == m.end())
                    m.insert({ temp, 1 });
                else
                {
                    m[temp]++;
                    mxOrder = max(m[temp], mxOrder);
                }
            } while (next_permutation(comb.begin(), comb.end()));
        }

        // 최대 주문횟수가 2회보다 적다면 메뉴를 만들 수 없음.
        if (mxOrder < 2) continue;

        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            if (mxOrder != iter->second) continue;

            answer.push_back(iter->first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}