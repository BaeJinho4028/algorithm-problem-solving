#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    if (direction == "right") {
        int en = numbers.back();
        numbers.pop_back();
        numbers.insert(numbers.begin(), en);
    } else {
        int st = numbers.front();
        numbers.erase(numbers.begin());
        numbers.push_back(st);
    }
    return numbers;
}