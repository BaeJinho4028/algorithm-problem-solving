#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    for (string& d : dic) {
        bool flag = true;
        for (string& s : spell) {
            if (d.find(s) == string::npos) {
                flag = false;
                break;
            }
        }
        if (flag) {
            answer = 1;
            break;
        } 
    }
    return answer;
}