#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; ++i) {
        bool odd = false;
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                odd = !odd;
            }
        }
        answer += (odd ? -i : i);
    }
    return answer;
}