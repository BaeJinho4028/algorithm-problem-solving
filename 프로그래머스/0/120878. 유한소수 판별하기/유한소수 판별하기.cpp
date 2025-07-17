#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    b /= gcd(a, b);
    
    while (b % 2 == 0) b /= 2;
    while (b % 5 == 0) b /= 5;
    
    return (b == 1) ? 1 : 2;
}