#include <bits/stdc++.h>

using namespace std;

vector<int> dice_pick;
vector<int> best_dice;
int mx = -1;

vector<int> sums(vector<vector<int>>& dice, vector<int>& pick) {
    vector<int> sums = {0};
    for (int idx : pick) {
        vector<int> nxt;
        for (int d : dice[idx]) {
            for (int s : sums) {
                nxt.push_back(s + d);
            }
        }
        sums = move(nxt);
    }
    sort(sums.begin(), sums.end());
    return sums;
}

void dfs(int st, int n, vector<vector<int>>& dice) {
    if (dice_pick.size() == n / 2) {
        vector<int> a = dice_pick;
        vector<int> b;
        
        for (int i = 0; i < n; ++i) {
            if (find(a.begin(), a.end(), i) == a.end()) {
                b.push_back(i);
            }
        }
        
        vector<int> a_sums = sums(dice, a);
        vector<int> b_sums = sums(dice, b);
        
        long long win = 0;
        for (int s : a_sums) {
            win += upper_bound(b_sums.begin(), b_sums.end(), s - 1) - b_sums.begin();
        }
        
        if (win > mx) {
            mx = win;
            best_dice = a;
        }
        return;
    }
    
    for (int i = st; i < n; ++i) {
        dice_pick.push_back(i);
        dfs(i + 1, n, dice);
        dice_pick.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    int half = n / 2;
    
    dfs(0, n, dice);
    
    vector<int> answer;
    for (int i : best_dice) {
        answer.push_back(i + 1);
    }
    return answer;
}