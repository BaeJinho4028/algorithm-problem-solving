#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    int st = 0;
    int en = num_list.size() - 1;
    int it = 1;
    
    switch(n) {
        case 1:
            en = slicer[1];
            break;
        case 2:
            st = slicer[0];
            break;
        case 3:
            st = slicer[0];
            en = slicer[1];
            break;
        case 4:
            st = slicer[0];
            en = slicer[1];
            it = 2;
            break;
    }
    for (int i = st; i <= en; i += it) {
        answer.push_back(num_list[i]);
    }
    return answer;
}