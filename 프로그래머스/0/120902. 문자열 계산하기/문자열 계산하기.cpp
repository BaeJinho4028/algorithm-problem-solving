#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    stringstream ss(my_string);
    int x, y;
    char op;
    
    ss >> x;
    while (ss >> op >> y) {
        if (op == '+') x += y;
        else if (op == '-') x -= y;
    }
    return x;
}