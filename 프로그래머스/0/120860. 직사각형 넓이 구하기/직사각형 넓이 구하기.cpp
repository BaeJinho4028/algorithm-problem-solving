#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> dots) {
    int mnX = dots[0][0], mxX = dots[0][0];
    int mnY = dots[0][1], mxY = dots[0][1];
    
    for (const auto& d : dots) {
        mnX = min(mnX, d[0]);
        mxX = max(mxX, d[0]);
        mnY = min(mnY, d[1]);
        mxY = max(mxY, d[1]);
    }
    
    return (mxX - mnX) * (mxY - mnY);
}
