#include <string>
#include <vector>
#include <numeric>

using namespace std;

string solution(vector<string> arr) {
    return accumulate(arr.begin(), arr.end(), string(""));
}