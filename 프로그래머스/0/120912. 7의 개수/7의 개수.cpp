#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for (int a : array) {
        while (a) {
            answer += (a % 10 == 7);
            a /= 10;
        }
    }
    return answer;
}