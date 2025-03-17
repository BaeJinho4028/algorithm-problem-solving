#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    
    vector<int> answer;
    int cnt = 0;
    multiset<int, less<int>> ms;
    
    for (string op : operations) {
        char o;
        int val;
        stringstream ss(op);
        ss >> o >> val;
        if (o == 'I') {
            ms.insert(val);
        }
        else if (!ms.empty()) {
            if (val == 1) {
                ms.erase(--ms.end());
            }
            else if (val == -1) {
                ms.erase(ms.begin());
            }
        }
    }
    
    if (ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }
    return answer;
}