#include <string>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for (int i = 0; i < myString.size() - pat.size() + 1; ++i) {
        if (myString.substr(i, pat.size()) == pat) {
            answer++;
        }
    }
    return answer;
}