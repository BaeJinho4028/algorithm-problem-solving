#include <string>
#include <vector>

using namespace std;

// 시작 : 나가는 것만 있고 들어가는건 없음 (2개 이상)
// 도넛 : 나가는것 들어오는것 1개씩
// 막대 : 나가는것 들어오는것 둘중 1개
// 8자 : 중간점은 나가는것과 들어가는것이 2개씩

vector<int> solution(vector<vector<int>> edges) {
    int MX = 1'000'001;
    vector<int> od(MX), id(MX);
    
    for (auto& e : edges) {
        od[e[0]]++;
        id[e[1]]++;
    }
    
    int st = 0, x = 0, y = 0, z = 0;
    
    for (int i = 1; i < MX; ++i) {
        if (od[i] >= 2 && id[i] == 0) st = i;
        else if (od[i] == 0 && id[i] >= 1) y++;
        else if (od[i] >= 2 && id[i] >= 2) z++;
    }
    
    x = od[st] - y - z;
    
    return {st, x, y, z};
}