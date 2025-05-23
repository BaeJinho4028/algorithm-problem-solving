#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    int x = a + b + c;
    int y = a * a + b * b +c * c;
    int z = a * a * a + b * b * b + c * c * c;
    if (a == b && b == c) {
        return x * y * z;
    }
    if (a == b || b == c || a == c) {
        return x * y;
    }
    return x;
}