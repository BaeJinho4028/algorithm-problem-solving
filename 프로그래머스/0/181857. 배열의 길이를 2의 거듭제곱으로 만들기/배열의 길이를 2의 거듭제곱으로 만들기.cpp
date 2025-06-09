#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int tmp = 1;
    while (tmp < arr.size()) {
        tmp *= 2;
    }
    
    arr.resize(tmp, 0);
    return arr;
}