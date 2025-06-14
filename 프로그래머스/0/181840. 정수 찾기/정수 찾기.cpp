#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    return count(num_list.begin(), num_list.end(), n) > 0;
}