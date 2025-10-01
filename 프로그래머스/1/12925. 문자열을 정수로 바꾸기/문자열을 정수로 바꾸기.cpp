#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int tmp;
    if (s[0] == '-') {
        tmp = -stoi(s.substr(1));
    } else if (s[0] == '+') {
        tmp = stoi(s.substr(1));
    } else {
        tmp = stoi(s);
    }
    return tmp;
}