#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
    stringstream ss(polynomial);
    int x = 0;
    int c = 0;
    string tmp;
    
    while (ss >> tmp) {
        if (tmp == "+") continue;
        
        if (tmp.back() == 'x') {
            string coeff = tmp.substr(0, tmp.size() - 1);
            if (coeff.empty()) {
                x += 1;
            } else {
                x += stoi(coeff);
            }
        } else {
            c += stoi(tmp);
        }
    }
    
    string answer;
    if (x != 0) {
        if (x == 1) {
            answer = "x";
        } else {
            answer = to_string(x) + "x";
        } 
    }
    if (c != 0) {
        if (!answer.empty()) {
            answer += " + ";
        }
        answer += to_string(c);
    }
    return answer;
}