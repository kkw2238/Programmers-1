#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

// 공백별로 단어를 분리하는 함수
vector <string> split(string s, string divid) {
    vector <string> v;

    char* c = strtok((char*)s.c_str(), divid.c_str());

    while (c) {
        v.push_back(c);
        c = strtok(NULL, divid.c_str());
    }

    return v;
}

string solution(string s) {
    string answer = "";

    vector <string> v = split(s, " ");
    char tmp = ' ';

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            if (j % 2 == 0) { // 짝수
                answer.push_back(toupper(v[i][j]));
            }
            else {
                answer.push_back(tolower(v[i][j]));
            }
        }

        if (i != (v.size() - 1)) {
            answer.push_back(tmp);
        }
    }

    return answer;
}