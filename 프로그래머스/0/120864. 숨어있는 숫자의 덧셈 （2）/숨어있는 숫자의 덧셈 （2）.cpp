#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int sum = 0;
    bool flag = false;
    for (char c : my_string) {
        if (isdigit(c)) {
            sum = sum * 10 + (c - '0');
            flag = true;
        } else {
            if (flag) {
                answer += sum;
                sum = 0;
                flag = false;
            }
        }
    }
    if (flag) {
        answer += sum;
    }
    return answer;
}