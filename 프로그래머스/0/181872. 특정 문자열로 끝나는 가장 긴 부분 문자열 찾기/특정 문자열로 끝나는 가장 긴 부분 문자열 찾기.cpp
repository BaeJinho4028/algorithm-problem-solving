#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    size_t pos = myString.rfind(pat);
    if (pos == string::npos) {
        return "";
    }
    return myString.substr(0, pos + pat.size());
}