#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isForbidden(int num) {
    // 3의 배수인지 확인
    if (num % 3 == 0) return true;

    // 숫자에 3이 포함되어 있는지 확인
    while (num > 0) {
        if (num % 10 == 3) return true;
        num /= 10;
    }

    return false;
}

int solution(int n) {
    int count = 0;
    int number = 0;

    // 3x 마을에서 사용하는 숫자를 찾을 때까지 반복
    while (count < n) {
        number++;
        if (!isForbidden(number)) {
            count++;
        }
    }

    return number;
}
