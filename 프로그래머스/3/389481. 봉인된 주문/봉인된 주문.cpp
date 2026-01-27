#include <bits/stdc++.h>

using namespace std;

string solution(long long n, vector<string> bans) {    
    vector<long long> chk;
    
    for (string b : bans) {
        long long tmp = 0;
        for (char c : b) {
            tmp = tmp * 26 + (c - 'a' + 1);
        }
        chk.push_back(tmp);
    }
    
    sort(chk.begin(), chk.end());

    for (long long b : chk) {
        if (n >= b) n++;
    }
        
    string ans = "";
    n--;
    
    while (n >= 0) {
        ans.push_back('a' + (n % 26));
        n = n / 26 - 1;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}