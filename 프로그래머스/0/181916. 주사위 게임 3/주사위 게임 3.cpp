#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) {
    vector<int> v = {a, b, c, d};
    sort(v.begin(), v.end());
    
    if (v[0] == v[3]) {
        return 1111 * v[0];
    }
    else if (v[0] == v[2]) {
        return (10 * v[0] + v[3]) * (10 * v[0] + v[3]);
    }
    else if (v[1] == v[3]) {
        return (10 * v[1] + v[0]) * (10 * v[1] + v[0]);
    }
    else if(v[0] == v[1]) {
        if(v[2] == v[3]) return (v[0] + v[2]) * abs(v[0] - v[2]);
        else return v[2] * v[3];
    }
    else if(v[1] == v[2]) {
        if(v[0] == v[3]) return (v[0] + v[1]) * abs(v[0] - v[1]);
        else return v[0] * v[3];
    }
    else if(v[2] == v[3]) {
        if(v[0] == v[1]) return (v[0] + v[2]) * abs(v[0] - v[2]);
        else return v[0] * v[1];
    }
    return v[0];
}