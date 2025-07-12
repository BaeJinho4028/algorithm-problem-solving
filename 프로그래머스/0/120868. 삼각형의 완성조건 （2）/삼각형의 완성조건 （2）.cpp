#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int sum = sides[0] + sides[1];
    int mx = max(sides[0], sides[1]);
    int mn = min(sides[0], sides[1]);
    return (mx - (mx - mn)) + (sum - mx) - 1;
}