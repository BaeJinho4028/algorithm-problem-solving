#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    
    map<char, int> ma;
    
    for (int i = 0; i < survey.size(); ++i) {
        ma[survey[i][0]] += max(0, 4- choices[i]);
        ma[survey[i][1]] += max(0, choices[i] - 4);
    }
    
    string answer = "";
    answer += (ma['R'] >= ma['T'] ? 'R' : 'T');
    answer += (ma['C'] >= ma['F'] ? 'C' : 'F');
    answer += (ma['J'] >= ma['M'] ? 'J' : 'M');
    answer += (ma['A'] >= ma['N'] ? 'A' : 'N');

    return answer;
}