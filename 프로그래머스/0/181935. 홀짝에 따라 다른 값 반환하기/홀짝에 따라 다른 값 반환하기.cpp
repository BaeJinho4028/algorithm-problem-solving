#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 2) ? n : n * n;
        n -= 2;
    }
    return sum;
}