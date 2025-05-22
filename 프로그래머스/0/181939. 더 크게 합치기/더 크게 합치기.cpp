#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    
    if (stoi(ab) > stoi(ba)) {
        return stoi(ab);
    }
    return stoi(ba);
}