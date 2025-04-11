//
// Created by tiago-oliveira on 14-03-2025.
//
#include "fraction.h"
#include <iostream>
using namespace std;
// ALGORITHM EUCLIDES
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// Função para tornar a fração irredutível
void simplify(fraction &f) {
    int divisor = gcd(f.num, f.den);
    f.num /= divisor;
    f.den /= divisor;
}
fraction add(fraction a, fraction b) {
    fraction c{};
    c.num=a.num*b.den+b.num*a.den;
    c.den=a.den*b.den;
    if (c.num==0) c.den=1;
    else simplify(c);
    if (c.den<0) {
        c.den=abs(c.den);
        c.num=-c.num;
    }
    return c;
}
fraction mul(fraction a, fraction b) {
    fraction c{};
    c.num=a.num*b.num;
    c.den=a.den*b.den;
    if (c.num==0) c.den=1;
    else simplify(c);
    if (c.den<0) {
        c.den=abs(c.den);
        c.num=-c.num;
    }
    return c;
}
int main () {
    { fraction a { 0, 1 }, b { 2, 1};
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    { fraction a { 1, 1 }, b { -1, 2};
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    { fraction a { -3, 2 }, b { 3, 2 };
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    { fraction a { -3, 2 }, b { -2, 3 };
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    { fraction a { -7, 24 }, b { 1, 3 };
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    { fraction a { -8, 25 }, b { 3, 4 };
        std::cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    std::cout << add({7,4536}, mul({-5,21}, add({1,2}, mul({-2,3}, {1,9})))) << '\n';
    return 0;
}