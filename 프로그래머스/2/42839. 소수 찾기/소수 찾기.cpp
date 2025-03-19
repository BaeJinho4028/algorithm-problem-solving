#include <bits/stdc++.h>
using namespace std;



int solution(string numbers) {   
    
    const int MAX_NUM = 10000000;
    vector<int> prime(MAX_NUM, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAX_NUM; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < MAX_NUM; j += i) {
                prime[j] = false;
            }
        }
    }
    
    sort(numbers.begin(), numbers.end());
    unordered_set<int> primes;
    
    do {
        for (int len = 1; len <= numbers.size(); ++len) {
            int num = stoi(numbers.substr(0, len));
            if (prime[num]) primes.insert(num);
        } 
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    return primes.size();
}