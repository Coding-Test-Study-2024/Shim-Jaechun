//프로그래머스 레벨2 방금그곡

//조건
//1. 음악길이보다 재생시간이 길 경우 반복재생
//2. 재생시간보다 음악길이가 짧을 경우 재생시간 만큼만 재생
//3. 조건이 일치하는 음악이 여러 개일 경우 재생된 시간이 제일 긴 음악 제목 반환
//4. 모두 같을 경우 먼저 입력된 음악 제목을 반환
//5. 음악이 없을 경우 (None) 반환

//A# -> 소문자 a로 변환

//A a# -> a
//B
//C c# -> c
//D d# -> d
//E
//F f# -> f
//G g# -> g

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int TimeDistToInt(string s, string e)
{
    int hour = stoi(e.substr(0, 2)) - stoi(s.substr(0, 2));
    int minu = stoi(e.substr(3, 2)) - stoi(s.substr(3, 2));

    if (minu < 0)
        return (hour - 1) * 60 + (60 + minu);
    else
        return hour * 60 + minu;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int maxTime = 0;
    string convertM = "";


    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] == '#')
        {
            convertM.back() += 32;
            continue;
        }
        convertM += m[i];
    }

    vector<pair<string, string>> vec;
    for (int i = 0; i < musicinfos.size(); i++)
    {
        // 문자입력 반복횟수 
        int reps = TimeDistToInt(musicinfos[i].substr(0, 5), musicinfos[i].substr(6, 5));
        // 입력할 문자 인덱스
        int curIndex = 0;

        //         // 제목, 곡
        vec.push_back({ "","" });

        string temp = "";
        for (int j = 12; j < musicinfos[i].length(); j++)
        {
            if (musicinfos[i][j] == ',')
            {
                // 제목 할당
                vec[i].first = temp;
                temp = "";
                continue;
            }

            temp += musicinfos[i][j];

            if (j == musicinfos[i].length() - 1)
            {
                // 곡 할당
                while (reps--)
                {
                    if (temp[curIndex] == '#')
                        reps++;     // #이 나온경우 반복횟수를 원복
                    else
                    {
                        if (curIndex < temp.length() - 1 && temp[curIndex + 1] == '#')
                            vec[i].second += temp[curIndex] + 32;
                        else
                            vec[i].second += temp[curIndex];
                    }

                    curIndex++;
                    if (curIndex >= temp.length())
                        curIndex = 0;
                }

                // 원형 리스트 생성
                string rev = vec[i].second;
                reverse(rev.begin(), rev.end());
                vec[i].second += rev;
            }
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].second.find(convertM) != string::npos
            && maxTime < vec[i].second.length())
        {
            maxTime = vec[i].second.length();
            answer = vec[i].first;
        }
    }

    if (answer.size() < 1)
        return "(None)";

    return answer;
}
