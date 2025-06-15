#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int r = arr.size();
    int c = arr[0].size();
    int mx = max(r, c);
    
    if (r > c) {
        for (auto& a : arr) {
            a.resize(mx, 0);
        }
    } else {
        vector<int> tmp(mx, 0);
        for (int i = 0; i < arr.size() - mx; ++i) {
            arr.push_back(tmp);            
        }
    }
    return arr;
}