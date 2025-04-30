//
// Created by tiago-oliveira on 18-02-2025.
//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main () {
    double total=0;
    int k, d;
    cin >> k >> d;
    for (int i=0; i<=k; i++) {
        total+=(pow((-1), i)/(2*i+1));
    }
    total=4*total;
    cout << fixed << setprecision(d) << total;
    return 0;
}