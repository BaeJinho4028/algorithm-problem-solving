#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    if (A == B) return 0;
    
    for (int i = 1; i < A.length(); ++i) {
        A = A.back() + A.substr(0, A.length() - 1);
        if (A == B) return i;
    }
    
    return -1;
}