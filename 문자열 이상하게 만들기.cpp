#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index = 0;
    for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
        if (*iter == ' ') { // ����
            answer.push_back(*iter);
            index = 0;
        }
        else { // �ܾ�
            if (index % 2 == 0) { // ¦��
                answer.push_back(toupper(*iter));
            }
            else { // Ȧ��
                answer.push_back(tolower(*iter));
            }

            ++index;
        }
    }
    return answer;
}