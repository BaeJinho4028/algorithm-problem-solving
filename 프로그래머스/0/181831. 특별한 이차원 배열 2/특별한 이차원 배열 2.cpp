#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    bool flag = true;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] != arr[j][i]) {
                flag = false;
            }
        }
    } 
    return flag;
}