#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int ROOT = 1;
int vis = 2;
const int MX = 500 * 40 + 5;
int depth[MX];
unordered_map<string, int> child[MX];
string name[MX];

void insert(vector<string>& route) {
    int cur = ROOT;
    for (string& s : route) {
        int& nxt = child[cur][s];
        if (nxt == 0) {
            nxt = vis++;
        }
        depth[nxt] = depth[cur] + 1;
        name[nxt] = s;
        cur = nxt;
    }
}

void dfs(int v) {
    if (v != ROOT) {
        for (int i = 0; i < depth[v]; ++i) {
            cout << ' ';
        }
        cout << name[v] << '\n';
    }

    vector<pair<string, int>> arr(child[v].begin(), child[v].end());
    sort(arr.begin(), arr.end());
    
    for (auto& a : arr) {
        dfs(a.Y);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    depth[ROOT] = -1;
    while (n--) {
        string s;
        cin >> s;
        string cur = "";
        vector<string> route;

        for (char c : s) {
            if (c == '\\') {
                route.push_back(cur);
                cur = "";
            } else {
                cur += c;
            }
        }
        route.push_back(cur);
        insert(route);
    }
    dfs(ROOT);
}

