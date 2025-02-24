#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    vector<int> answer;
    int pre;
    for (int n : arr) {
        if (pre != n) {
            answer.emplace_back(n);
        }
        pre = n;
    }
    
    return answer;
}