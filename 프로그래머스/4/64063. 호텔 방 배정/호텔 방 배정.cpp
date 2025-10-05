#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> um;

long long find(long long x) {
    if (um.find(x) == um.end()) return x;
    else return um[x] = find(um[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    answer.reserve(room_number.size());
    for (long long x : room_number) {
        long long y = find(x);
        answer.push_back(y);
        um[y] = y + 1;
    }
    return answer;
}