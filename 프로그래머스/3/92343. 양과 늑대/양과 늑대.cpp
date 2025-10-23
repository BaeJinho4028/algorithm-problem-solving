#include <bits/stdc++.h>
using namespace std;

vector<int> graph[20];
int answer = 0;

void dfs(int sheep, int wolf, vector<int>& info, vector<bool> visited) {
    // 양이 늑대보다 많을 때만 갱신
    answer = max(answer, sheep);

    for (int i = 0; i < info.size(); i++) {
        if (!visited[i]) continue; // 현재까지 방문 가능한 노드만 탐색

        for (int child : graph[i]) {
            if (visited[child]) continue; // 이미 방문한 곳은 건너뜀

            visited[child] = true; // 방문 표시

            if (info[child] == 0) {
                dfs(sheep + 1, wolf, info, visited);
            } else if (sheep > wolf + 1) {
                dfs(sheep, wolf + 1, info, visited);
            }

            visited[child] = false; // 백트래킹
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for (auto& e : edges) {
        graph[e[0]].push_back(e[1]);
    }

    vector<bool> visited(info.size(), false);
    visited[0] = true; // 루트부터 시작 (항상 양)
    dfs(1, 0, info, visited);

    return answer;
}

int main() {
    vector<int> info = {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edges = {
        {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},
        {4,3},{6,5},{4,6},{8,9}
    };

    cout << solution(info, edges) << "\n"; // 5 출력
}
