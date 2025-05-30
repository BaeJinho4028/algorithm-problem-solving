#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> idx;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 2) {
            idx.push_back(i);
        }
    }
    
    if (idx.empty()) {
        return {-1};
    }
    
    return vector<int>(arr.begin() + idx[0], arr.begin() + idx.back() + 1);
}