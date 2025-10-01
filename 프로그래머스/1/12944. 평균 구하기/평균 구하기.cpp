#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    return (double)accumulate(arr.begin(), arr.end(), 0) / arr.size();
}