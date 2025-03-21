#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool chk(ll mid, int n, const vector<int>& times) {
    ll cnt = 0;
    for (int t : times) {
        cnt += mid / t;
    }
    return cnt >= n;
}

long long solution(int n, vector<int> times) {
    ll st = 0;
    ll en = *max_element(times.begin(), times.end()) * (ll)n;
    
    while (st <= en) {
        ll mid = (st + en) / 2;
        if (chk(mid, n, times)) en = mid - 1;
        else st = mid + 1;
    }
    
    return st;
}