#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    bool mode = false;
    string ret = "";
    
    for (int i = 0; i < code.size(); ++i) {
        if (code[i] == '1') {
            mode = !mode;
            continue;
        }
        
        bool odd = i % 2;
        if (mode && odd) {
            ret.push_back(code[i]);
        }
        else if (!mode && !odd) {
            ret.push_back(code[i]);
        }
    }
    
    if (ret == "") {
        return "EMPTY";
    }
    return ret;
}