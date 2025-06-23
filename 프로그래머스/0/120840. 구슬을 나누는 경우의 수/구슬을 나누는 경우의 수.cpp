#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int balls, int share) {
    share = min(share, balls - share);
    if (share == 0) return 1;
    long long res = solution(balls - 1, share - 1);
    return res * balls / share;
}