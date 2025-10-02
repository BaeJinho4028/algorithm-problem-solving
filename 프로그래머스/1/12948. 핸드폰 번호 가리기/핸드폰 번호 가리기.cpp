#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int n = phone_number.size();
    return string(n - 4, '*') + phone_number.substr(n - 4);
}