#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> ma;
    for(auto s : completion)
        ma[s]++;
    
    for(auto s : participant)
        ma[s]--;
    
    for(auto s : participant)
        if(ma[s] == -1) 
            return s;
}