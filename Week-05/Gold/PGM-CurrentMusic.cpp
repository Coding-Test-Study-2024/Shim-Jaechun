//���α׷��ӽ� ����2 ��ݱװ�

//����
//1. ���Ǳ��̺��� ����ð��� �� ��� �ݺ����
//2. ����ð����� ���Ǳ��̰� ª�� ��� ����ð� ��ŭ�� ���
//3. ������ ��ġ�ϴ� ������ ���� ���� ��� ����� �ð��� ���� �� ���� ���� ��ȯ
//4. ��� ���� ��� ���� �Էµ� ���� ������ ��ȯ
//5. ������ ���� ��� (None) ��ȯ

//A# -> �ҹ��� a�� ��ȯ

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
        // �����Է� �ݺ�Ƚ�� 
        int reps = TimeDistToInt(musicinfos[i].substr(0, 5), musicinfos[i].substr(6, 5));
        // �Է��� ���� �ε���
        int curIndex = 0;

        //         // ����, ��
        vec.push_back({ "","" });

        string temp = "";
        for (int j = 12; j < musicinfos[i].length(); j++)
        {
            if (musicinfos[i][j] == ',')
            {
                // ���� �Ҵ�
                vec[i].first = temp;
                temp = "";
                continue;
            }

            temp += musicinfos[i][j];

            if (j == musicinfos[i].length() - 1)
            {
                // �� �Ҵ�
                while (reps--)
                {
                    if (temp[curIndex] == '#')
                        reps++;     // #�� ���°�� �ݺ�Ƚ���� ����
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

                // ���� ����Ʈ ����
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
