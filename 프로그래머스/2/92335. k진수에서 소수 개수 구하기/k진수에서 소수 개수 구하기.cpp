#include <bits/stdc++.h>

using namespace std;

vector<int> conv(int n, int k) {
    vector<int> v;
    while (n) {
        v.push_back(n % k);
        n /= k;
    }
    reverse(v.begin(), v.end());
    return v;
}

bool isprime(long long x) {
    if (x <= 1) return false;
    for (long long i = 2; i * i <= x; ++i){
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    vector<int> num = conv(n, k);
    
    int answer = 0;
    long long tmp = 0;
    for (int digit : num) {
        if (digit == 0) {
            answer += isprime(tmp);
            tmp = 0;
            continue;
        }
        tmp = 10 * tmp + digit;
    }
    answer += isprime(tmp);
    return answer;
}