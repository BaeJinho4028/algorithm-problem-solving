#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> next_room;

long long f(long long r) {
    if (next_room.find(r) == next_room.end()) {
        next_room[r] = r + 1;
        return r;
    }
    return next_room[r] = f(next_room[r]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    answer.reserve(room_number.size());
    
    for (auto r : room_number) {
        long long x = f(r);
        answer.push_back(x);
    }
    return answer;
}