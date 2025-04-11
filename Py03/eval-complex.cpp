//
// Created by tiago-oliveira on 17-03-2025.
//
#include "complex.h"
#include <iostream>
using namespace std;
complex sum(const complex p, const complex q) {
    complex c{};
    c.real=p.real+q.real;
    c.img=p.img+q.img;
    return c;
}
complex mult(const complex p, const complex q) {
    complex c{};
    c.real=p.real*q.real-p.img*q.img;
    c.img=p.real*q.img+q.real*p.img;
    return c;
}

complex eval(const complex a[], int n, complex x) {
    complex d=a[0];
    complex exp=x;
    if (n==1) return d;
    for (int i=1; i<n; i++) {
        complex e=mult(a[i], exp);
        d=sum(d, e);
        exp=mult(exp, x);
    }
    return d;
}
int main () {
    { const int n = 1;
        complex p[n] = { { 1, 2 } };
        complex x = { 3, 4 };
        complex r = eval(p, n, x);
        cout << r.real << ' ' << r.img << '\n'; }
    { const int n = 2;
        complex p[n] = { { 3, 4 }, { 1, 2 } };
        complex x = { 1, 2 };
        complex r = eval(p, n, x);
        cout << r.real << ' ' << r.img << '\n'; }
    {  const int n = 3;
        complex p[n] = { { 3, 0 }, { 1, 1 }, { 1, 0 } };
        complex x = { 2, 0 };
        complex r = eval(p, n, x);
        cout << r.real << ' ' << r.img << '\n'; }
    { const int n = 3;
        complex p[n] = { { 3, 0 }, { 1, 1 }, { 1, 0 } };
        complex x = { 2, 1 };
        complex r = eval(p, n, x);
        cout << r.real << ' ' << r.img << '\n'; }
    { const int n = 4;
        complex p[n] = { { 18, -12 }, { 3, -2 }, { 2, -1 }, { 1, 1 } };
        complex x = { -2, -1 };
        complex r = eval(p, n, x);
        cout << r.real << ' ' << r.img << '\n'; }
    return 0;
}