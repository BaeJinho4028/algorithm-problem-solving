#include <bits/stdc++.h>
using namespace std;

int dfs(const vector<int>& numbers, int target, int idx, int sum) {
    if (idx == numbers.size()) {
        return (sum == target);
    }
    
    int add = dfs(numbers, target, idx + 1, sum + numbers[idx]);
    int sub = dfs(numbers, target, idx + 1, sum - numbers[idx]);
    return add + sub;
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}