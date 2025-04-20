//
// Created by tiago-oliveira on 25-02-2025.
//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int solve_eq(int a, int b, int c, double& x1, double& x2) {
    int delta=b*b-4*a*c;
    int n;
    if (delta<0) {
        x1=NAN;
        x2=NAN;
        n=0;
    }
    else if (delta==0) {
        x1=(-b)/(2.0*a);
        x2=NAN;
        n=1;
    }
    else {
        x1=((-b)-sqrt(delta))/(2*a);
        x2=((-b)+sqrt(delta))/(2*a);
        n=2;
    }
    return n;
}
int main () {
    double x1, x2;
    int r = solve_eq(3, 4, -2, x1, x2);
    std::cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';
    return 0;
}