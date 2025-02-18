#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<int> se;
    for(auto num : nums) {
        se.insert(num);
    }
    
    return min(se.size(), nums.size()/2);
}