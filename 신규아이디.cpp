#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1�ܰ�: �빮��->�ҹ���
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    // 2�ܰ�: ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ�� ������ ��� ���� ����
    for (int i = 0; i < new_id.size(); ++i) {
        if (isdigit(new_id[i]) == 0 && islower(new_id[i]) == 0
            && new_id[i] != '_' && new_id[i] != '.' && new_id[i] != '-') {
            new_id.erase(new_id.begin() + i);
            --i;
        }
    }

    // 3�ܰ�: ��ħǥ(.)�� 2���̻� ���ӵ� �κ� �ϳ��� ����� ����
    for (int i = 0; i < new_id.size(); ++i) {
        if (new_id[i] == '.' && new_id[i] == new_id[i + 1]) {
            new_id.erase(new_id.begin() + i);
            --i;
        }
    }

    // 4�ܰ�: ��ħǥ(.)�� ó���̳� ���� �´ٸ� ����
    if(new_id.front() == '.'){
        new_id.erase(new_id.begin());
    }

    if (new_id.back() == '.') {
        new_id.erase(new_id.end() - 1);
    }

    // 5�ܰ�: ���ڿ��̶��, "a"�� �����Ѵ�.
    if (new_id.empty() == true) {
        new_id.push_back('a');
    }

    // 6�ܰ�: ���̰� 16�� �̻��̸�, ù 15���� ���ڸ� ������ ������ ���ڸ� ����
    if (new_id.size() >= 16) {
        new_id.erase(new_id.begin() + 15, new_id.end());
    }

    if (new_id.back() == '.') {
        new_id.erase(new_id.end() - 1);
    }

    // 7�ܰ�: new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� �� ���� �ݺ�
    if (new_id.size() <= 2) {
        while (new_id.size() != 3) {
            new_id.push_back(new_id.back());
        }
    }

    answer = new_id;
    return answer;
}