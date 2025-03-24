#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> arr) {
    vector<int> nums;
    vector<string> ops;
    for (int i = 0; i < arr.size(); ++i) {
        if (i % 2) ops.push_back(arr[i]);
        else nums.push_back(stoi(arr[i]));
    }
    
    int n = nums.size();
    vector d(n + 1, vector(n + 1, vector(2, -1)));
    
    auto dp = [&](auto&& self, int l, int r, bool is_max) -> int {
        int &ret = d[l][r][is_max];
        if (~ret) return ret;
        if (l == r) return ret = nums[l];
        
        ret = is_max ? -0x3f3f3f3f : 0x3f3f3f3f;
        
        for (int i = l; i < r; ++i) {
            if(ops[i] == "+") {
                int a = self(self, l, i, true) + self(self, i+1, r, true);
                int b = self(self, l, i, false) + self(self, i+1, r, false);
                ret = is_max ? max({ret,a,b}) : min({ret,a,b});
            }
            else {
                int a = self(self, l, i, true) - self(self, i+1, r, false);
                int b = self(self, l, i, false) - self(self, i+1, r, true);
                ret = is_max ? max({ret,a,b}) : min({ret,a,b});
            }
        }
        return ret;
    };

    return dp(dp, 0, arr.size() / 2, true);
}