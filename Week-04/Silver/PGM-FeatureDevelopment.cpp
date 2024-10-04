// ���α׷��ӽ� ����2 ��ɰ���

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // ��¥ ī��Ʈ, �Ϸ�� �۾� ī��Ʈ
    int dayCnt = 0, doneCnt = 0;
    for (int i = 0; i < progresses.size(); i++)
    {
        // �۾��� ���� ���൵
        int curPGS = progresses[i] + speeds[i] * dayCnt;

        // ���� �۾��� �̹� ����� ���
        if (curPGS >= 100) doneCnt++;
        // �߰��� �۾��� �����ؾ� �ϴ� ���
        else
        {
            // ������ ����� �۾� ����
            if (dayCnt)
                answer.push_back(doneCnt);

            dayCnt += (100 - curPGS) % speeds[i] > 0 ? (100 - curPGS) / speeds[i] + 1 : (100 - curPGS) / speeds[i];
            doneCnt = 1;
        }
    }

    if (doneCnt)
        answer.push_back(doneCnt);

    return answer;
}