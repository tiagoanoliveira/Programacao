//
// Created by tiago-oliveira on 17-03-2025.
//
#include "fraction.h"
#include <iostream>
using namespace std;
fraction sum(const fraction p, const fraction q) {
    fraction c{};
    if (p.den==q.den) {
        c.den=p.den;
        c.num=p.num+q.num;
    }
    else {
        c.den=p.den*q.den;
        c.num=p.num*q.den+q.num*p.den;
    }
    return c;
}
fraction mult(const fraction p, const fraction q) {
    fraction c{};
    c.den=p.den*q.den;
    c.num=p.num*q.num;
    return c;
}
fraction eval(const fraction a[], int n, fraction x) {
    fraction d=a[0];
    fraction exp=x;
    if (n==1) return d;
    for (int i=1; i<n; i++) {
        fraction e=mult(a[i], exp);
        d=sum(d, e);
        exp=mult(exp, x);
    }
    return normalize(d);
}
int main () {
    { const int n = 1;
        fraction p[n] = { { 1, 2 } };
        fraction x = { 3, 4 };
        fraction r = eval(p, n, x);
        cout << r.num << '/' << r.den << '\n'; }
    { const int n = 2;
        fraction p[n] = { { -3, 4 }, { -1, 2 } };
        fraction x = { 0, 1 };
        fraction r = eval(p, n, x);
        cout << r.num << '/' << r.den << '\n'; }
    { const int n = 4;
        fraction p[n] = { { 1, 1 }, { 0, 1 }, { 0, 1 }, { 1, 1 } };
        fraction x = { 2, 1 };
        fraction r = eval(p, n, x);
        cout << r.num << '/' << r.den << '\n'; }
    { const int n = 3;
        fraction p[n] = { { 0, 1 }, { 1, 1 }, { 1, 2 } };
        fraction x = { 1, 2 };
        fraction r = eval(p, n, x);
        cout << r.num << '/' << r.den << '\n'; }
    { const int n = 4;
        fraction p[n] = { { -1, 2 }, { 1, 2 }, { -1, 2 }, { 1, 2 } };
        fraction x = { -1, 3 };
        fraction r = eval(p, n, x);
        cout << r.num << '/' << r.den << '\n'; }
    return 0;
}