#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    for (char c : control) {
        switch (c) {
            case 'w':
                n += 1;
                continue;
            case 's':
                n -= 1;
                continue;
            case 'd':
                n += 10;
                continue;
            case 'a':
                n -= 10;
                continue;
        }
    }
    return n;
}