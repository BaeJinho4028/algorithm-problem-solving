#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    string s = "";
    for (char c : myStr) {
        if (c == 'a' || c == 'b' || c == 'c') {
            if (!s.empty()) {
                answer.push_back(s);
                s.clear();
            }
        } else {
            s += c;
        }
    }
    if (!s.empty()) {
        answer.push_back(s);
    }
    return answer.size() == 0 ? vector<string>{"EMPTY"} : answer;
}