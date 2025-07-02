#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    auto it = max_element(array.begin(), array.end());
    return {*it, int(it - array.begin())};
}