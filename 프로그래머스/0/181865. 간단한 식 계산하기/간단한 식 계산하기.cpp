#include <string>
#include <sstream>

using namespace std;

int solution(string binomial) {
    int a, b;
    char op;
    istringstream iss(binomial);
    iss >> a >> op >> b;
    
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
}