#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 1; i < phone_book.size(); ++i) {
        if(phone_book[i-1] == phone_book[i].substr(0, phone_book[i-1].size())) {
            return false;
        }
    }
    return true;
}