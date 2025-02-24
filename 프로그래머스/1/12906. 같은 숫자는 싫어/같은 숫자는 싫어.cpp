#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}