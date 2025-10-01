#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int origin = x;
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return (origin % sum == 0);
}