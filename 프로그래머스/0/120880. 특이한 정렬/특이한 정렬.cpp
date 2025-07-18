#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    sort(numlist.begin(), numlist.end(), [n](int a, int b) {
        int da = abs(a - n);
        int db = abs(b - n);
        if (da == db) return a > b;
        return da < db;
    });
    return numlist;
}