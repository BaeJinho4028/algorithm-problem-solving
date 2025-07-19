#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    for(auto& s : score) {
        s.push_back(s[0] + s[1]);
    }

    for(const auto v : score) {
        int count = 0;
        for(const auto t : score) {
            count += (t[2] > v[2]);
        }
        answer.push_back(count + 1);
    }

    return answer;
}