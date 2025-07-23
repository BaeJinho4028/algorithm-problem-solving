#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
    int num1 = stoi(bin1, nullptr, 2);    
    int num2 = stoi(bin2, nullptr, 2);    
    int sum = num1 + num2;
    
    string answer = "";
    while (sum > 0) {
        answer = char((sum % 2) + '0') + answer;
        sum /= 2;
    }
    
    return answer.empty() ? "0" : answer;
}