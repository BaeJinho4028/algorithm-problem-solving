#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string odd = "";
    string even = "";
    for (int n : num_list) {
        n % 2 ? odd += to_string(n) : even += to_string(n);
    }
    return stoi(odd) + stoi(even);
}