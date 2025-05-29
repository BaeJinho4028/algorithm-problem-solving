#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer(start_num - end_num + 1);
    iota(answer.rbegin(), answer.rend(), end_num);
    return answer;
}