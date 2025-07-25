#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    char t = k + '0';
    for (int a = i; a <= j; ++a) {
        string s = to_string(a);
        for (char c : s) {
            if (c == t) {
                answer++;
            }
        }
    }
    return answer;
}