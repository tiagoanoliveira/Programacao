//
// Created by tiago-oliveira on 15-03-2025.
//
#include <cmath>
#include <iostream>
using namespace std;
unsigned int area(const float base, const float height) {
    return round(base*height/2);
}
unsigned int area(const float a, const float b, const float c) {
    float s=(a+b+c)/2;
    unsigned int ar=round(sqrt(s*(s-a)*(s-b)*(s-c)));
    return ar;
}
int main () {
    { int a = area(4, 6); std::cout << a << '\n'; }
    { int a = area(6, 6, 5); std::cout << a << '\n'; }
    { int a = area(3, 3); std::cout << a << '\n'; }
    return 0;
}