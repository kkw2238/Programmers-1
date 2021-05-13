#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int solution_d(string dartResult) {
    // �� ����
    int answer = 0;

    // �ܰ躰 string
    vector <string> stage;
    
    // �ܰ躰 �ؼ�
    vector <int> base;

    // �ܰ躰 ����
    vector <int> score;
    
    // �� ������ �� �������� ����
    for (int i = 0; i <= dartResult.size(); ++i) {
        if (isupper(dartResult[i]) != 0) {
            if (dartResult[i + 1] == '*' || dartResult[i + 1] == '#'){
                if (dartResult[i - 1] == '0' && isdigit(dartResult[i - 2]) != 0) {
                    stage.push_back(dartResult.substr(i - 2, 4));
                }
                else {
                    stage.push_back(dartResult.substr(i - 1, 3));
                }
            }
            else{
                if (dartResult[i - 1] == '0' && isdigit(dartResult[i - 2]) != 0) {
                    stage.push_back(dartResult.substr(i - 2, 3));
                }
                else {
                    stage.push_back(dartResult.substr(i - 1, 2));
                }
            }
        }
    }

    // �� ������ ������ base�� ����
    for (int i = 0; i < stage.size(); ++i) {
        // ���ڸ� score�� �ֱ�
        base.push_back(stoi(stage[i].substr(0, stage[i].length() - 1)));
    }

    // �� ������ ������ score���� ���(1)
    for (int i = 0; i < stage.size(); ++i) {
        // �빮�ڸ��� n��
        if (stage[i][1] == 'S' || stage[i][2] == 'S') {
            score.push_back(pow(base[i], 1));
        }
        else if (stage[i][1] == 'D' || stage[i][2] == 'D') {
            score.push_back(pow(base[i], 2));
        }
        else if (stage[i][1] == 'T' || stage[i][2] == 'T') {
            score.push_back(pow(base[i], 3));
        }
    }

    // �� ������ ������ score���� ���(2)
    for (int i = 0; i < score.size(); ++i) {
        // *
        if (stage[i][stage[i].length() - 1] == '*') {
            if (i == 0) {
                score[i] *= 2;
            }
            else {
                score[i - 1] *= 2;
                score[i] *= 2;
            }
        }

        // #
        if (stage[i][stage[i].length() - 1] == '#') {
            score[i] *= -1;
        }
    }

    // �� ����
    for (int i = 0; i < score.size(); ++i) {
        answer += score[i];
    }

    return answer;
}