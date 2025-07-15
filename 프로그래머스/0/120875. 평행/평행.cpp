#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    auto p = [&](int i1, int i2, int i3, int i4) {
        int dx1 = dots[i2][0] - dots[i1][0];
        int dy1 = dots[i2][1] - dots[i1][1];
        int dx2 = dots[i4][0] - dots[i3][0];
        int dy2 = dots[i4][1] - dots[i3][1];
        return dx1 * dy2 == dx2 * dy1;
    };
    
    if (p(0, 1, 2, 3) || p(0, 2, 1, 3) || p(0, 3, 1, 2)) return 1;
    return 0;
}