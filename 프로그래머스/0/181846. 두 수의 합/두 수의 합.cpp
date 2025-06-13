#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    int carry = 0;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    if (a.size() < b.size()) a.resize(b.size(), '0');
    else b.resize(a.size(), '0');
    
    for (int i = 0; i < a.size(); ++i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        answer += to_string(sum % 10);
    }
    
    if (carry) answer += to_string(carry);
    reverse(answer.begin(), answer.end());
    return answer;
}