#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string ans = "";
    for (string s : str_list) {
        if (s.find(ex) == string::npos) {
            ans += s;
        }
    }
    return ans;
}