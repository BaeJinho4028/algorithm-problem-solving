#include <bits/stdc++.h>

using namespace std;

string zero(string s) {
    int len = s.length();
    int full = 1;
    while (full - 1 < len) {
        full *= 2;
    }
    return s + string(full - 1 - len, '0');
}

int chk(string s) {
    int len = s.length();
    if (len < 3) return 1;
    if (s.find("1") == string::npos) return 1;
    
    if (s[len / 2] == '1') return chk(s.substr(0, len / 2)) && chk(s.substr(len/2 + 1));
    return 0;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (auto n : numbers) {
        string tree = "";
        
        while (n > 0) {
            tree += to_string(n % 2);
            n /= 2;
        }
        
        tree = zero(tree);
        answer.push_back(chk(tree));
    }
    
    return answer;
}