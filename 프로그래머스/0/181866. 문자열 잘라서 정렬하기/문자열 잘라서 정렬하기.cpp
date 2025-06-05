#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string s = "";
    for (char c : myString) {
        if (c == 'x') {
            if (!s.empty()) {
                answer.push_back(s);
            }
            s.clear();
            continue;
        }
        s += c;
    }
    if (!s.empty()) {
        answer.push_back(s);
    }
    sort(answer.begin(), answer.end());
    return answer;
}