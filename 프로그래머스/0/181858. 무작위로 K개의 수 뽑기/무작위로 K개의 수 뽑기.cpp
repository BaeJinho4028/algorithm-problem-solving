#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    unordered_map<int, int> cnt;
    
    for (const auto& i : arr) {
        if (cnt[i]++ == 0) {
            answer.push_back(i);
        }
    }
    answer.resize(k, -1);
    return answer;
}