#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);

        string word;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            cout << word;
            if (ss.peek() != EOF) cout << ' ';
        }
        cout << '\n';
    }
}
