#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (auto& q : queries) {
        for (int i = q[0]; i <= q[1]; ++i) {
            if (i % q[2]) {
                continue;
            }
            arr[i]++;
        }
    }
    return arr;
}