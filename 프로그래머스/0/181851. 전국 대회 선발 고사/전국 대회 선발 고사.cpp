#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    vector<pair<int, int>> v;
    for (int i = 0; i < rank.size(); ++i) {
        if (attendance[i]) {
            v.push_back({rank[i], i});
        }
    }
    sort(v.begin(), v.end());
    
    return v[0].second * 10000 + v[1].second * 100 + v[2].second;
}