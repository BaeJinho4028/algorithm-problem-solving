#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<string> nums;
    for (int num : numbers) {
        nums.push_back(to_string(num));
    }
    sort(nums.begin(), nums.end(), cmp);
    
    if(nums[0] == "0") return "0";
    
    string answer = "";
    for (string n : nums) {
        answer += n;
    }
    return answer;
}