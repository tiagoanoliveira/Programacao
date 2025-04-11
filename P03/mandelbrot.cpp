//
// Created by tiago-oliveira on 15-03-2025.
//
#include "complex.h"
#include <iostream>
using namespace std;
void mul(const complex& a, const complex& b, complex& r) {
    r.x=(a.x*b.x-a.y*b.y);
    r.y=(a.x*b.y+b.x*a.y);
}
void add(const complex& a, const complex& b, complex& r) {
    r.x=a.x+b.x;
    r.y=a.y+b.y;
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n) {
    z_n={0,0};
    complex t;
    for (unsigned int i=1; i<=n; i++) {
        mul(z_n,z_n,t);
        add(t, c, z_n);
    }
}
int main () {
    { complex z_n;
        mandelbrot({1.2, 3.4}, 0, z_n);
        std::cout << z_n << '\n'; }
    { complex z_n;
        mandelbrot({1, 1}, 1, z_n);
        std::cout << z_n << '\n'; }
    { complex z_n;
        mandelbrot({1, 1}, 2, z_n);
        std::cout << z_n << '\n'; }
    { complex z_n;
        mandelbrot({-1.2, 0.4}, 7, z_n);
        std::cout << z_n << '\n'; }
    { complex z_n;
        mandelbrot({0.1, 3.2}, 4, z_n);
        std::cout << z_n << '\n'; }
    { complex z_n;
        mandelbrot({-1, 0}, 11, z_n);
        std::cout << z_n << '\n'; }
    return 0;
}