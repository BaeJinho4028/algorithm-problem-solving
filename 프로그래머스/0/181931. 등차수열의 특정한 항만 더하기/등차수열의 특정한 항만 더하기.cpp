#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int sum = 0;
    for (bool flag : included) {
        if (flag) {
            sum += a;
        }
        a += d;
    }
    return sum;
}