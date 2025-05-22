#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    if (ineq == ">") {
        if (eq == "=") {
            return n >= m;
        } 
        return n > m;
    } 
    if (eq == "=") {
        return n <= m;
    }
    return n < m;
}