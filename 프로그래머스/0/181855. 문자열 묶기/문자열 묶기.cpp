#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    vector<int> cnt(31, 0);
    int answer = 0;
    for (string s : strArr) {
        cnt[s.size()]++;
    }
    
    return *max_element(cnt.begin(), cnt.end());
}