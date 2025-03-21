#include <bits/stdc++.h>
using namespace std;

void dfs(string cur, string& word, int& cnt, int& answer, string& aeiou) {
    cnt++;
    
    if (cur == word) {
        answer = cnt;
        return;
    }
    if (cur.size() == 5) {
        return;
    }
    
    for (int i = 0; i < 5; ++i) {
        cout << cur + aeiou[i] << ':' << word << '\n';
        dfs (cur + aeiou[i], word, cnt, answer, aeiou);
    }
}

int solution(string word) {
    int answer = 0, cnt = -1;
    string aeiou = "AEIOU";
    dfs("", word, cnt, answer, aeiou);
    return answer;
}