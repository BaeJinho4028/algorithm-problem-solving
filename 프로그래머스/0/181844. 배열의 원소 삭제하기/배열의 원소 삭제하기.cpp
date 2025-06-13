#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    for (int d : delete_list) {
        arr.erase(remove(arr.begin(), arr.end(), d), arr.end());
    }
    return arr;
}