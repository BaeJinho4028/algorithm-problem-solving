#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int sum = accumulate(num_list.begin(), num_list.end(), 0);
    int mul = accumulate(num_list.begin(), num_list.end(), 1, multiplies<int>());
    return (sum * sum > mul);
}