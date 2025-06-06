#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    string s;
    for (char c : myString) {
        s += (c == 'A') ? 'B' : 'A';
    }
    
    return !(s.find(pat) == string::npos);
}