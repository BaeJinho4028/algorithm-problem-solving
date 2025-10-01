#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    vector<int> chk(10);
    for (int x : numbers) {
        chk[x] = true;
    }
    
    int answer = 0;
    for (int i = 0; i < 10; ++i) {
        if (!chk[i]) answer += i;
    }    
    return answer;
}