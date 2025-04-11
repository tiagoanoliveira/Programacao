//
// Created by tiago-oliveira on 15-03-2025.
//
#include <iostream>
using namespace std;
void swapper(int& a, int& b) {
    int temp=a;
    a=b;
    b=temp;
}
int main () {
    { int a = 3; int b = 5; swapper(a, b);
        std::cout << a << ' ' << b << '\n'; }
    { int a = 2; int b = 4; swapper(a, b);
        std::cout << a << ' ' << b << '\n'; }
    return 0;
}