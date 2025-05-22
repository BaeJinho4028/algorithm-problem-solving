#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    for (int i = 0; i < strArr.size(); ++i) {
        for (char& c : strArr[i]) {
            c = (i % 2) ? toupper(c) : tolower(c);
        }
    }
    return strArr;
}