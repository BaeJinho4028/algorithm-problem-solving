#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int cnt = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int& a : arr) {
            if (a >= 50 && a % 2 == 0) {
                a /= 2;
                flag = true;
            } else if (a < 50 && a % 2) {
                a = 2 * a + 1;
                flag = true;
            }
        }
        cnt++;       
    }
    return cnt - 1;
}