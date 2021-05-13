#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution_p(vector<int> nums){
    int answer = 1;

    // ���� ���� ���� ��
    int select = (nums.size() / 2);
    select -= 1;

    // ����
    sort(nums.begin(), nums.end());

    // ���� ���õ� ��
    int current = nums[0];

    for (int i = 0; i < nums.size(); ++i) {
        if (select == 0) break;

        if (current != nums[i]) {
            current = nums[i];
            ++answer;
            --select;
        }
    }

    return answer;
}