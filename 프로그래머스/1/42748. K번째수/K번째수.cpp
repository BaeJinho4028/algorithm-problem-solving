#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (const auto& cmd : commands) {
        int st = cmd[0] - 1;
        int en = cmd[1] - 1;
        int k = cmd[2] - 1;
        vector<int> arr(array.begin() + st, array.begin() + en + 1);
        sort(arr.begin(), arr.end());
        
        answer.push_back(arr[k]);
    }
    return answer;
}