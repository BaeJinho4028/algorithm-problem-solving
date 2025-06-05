#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    istringstream iss(my_string);
    string s;
    while (iss >> s) {
        answer.push_back(s);
    }
    return answer;
}