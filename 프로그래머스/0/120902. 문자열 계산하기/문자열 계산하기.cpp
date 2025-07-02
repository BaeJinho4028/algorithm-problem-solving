#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    istringstream iss(my_string);
    int x, y;
    char op;
    
    iss >> x;
    while (iss >> op >> y) {
        if (op == '+') x += y;
        else if (op == '-') x -= y;
    }
    return x;
}