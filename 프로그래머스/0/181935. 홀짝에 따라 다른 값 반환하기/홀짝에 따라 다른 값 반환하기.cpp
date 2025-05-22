#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sum = 0;
    if (n % 2) {
        for (int i = 1; i <= n; i += 2) {
            sum += i;
        }
        return sum;
    }
    for (int i = 2; i <= n; i += 2) {
        sum += i * i;
    }
    return sum;
}