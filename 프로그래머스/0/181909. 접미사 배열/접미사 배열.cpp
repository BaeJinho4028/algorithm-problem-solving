#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    string tmp = "";
    set<int> se;
    for (int i = my_string.size() - 1; i >= 0; ++i) {
        tmp += my_string[i];
        se.insert(tmp);
    }
    
    for (string& s : se) {
        answer.push_back(s);
    }
    
    return answer;
}