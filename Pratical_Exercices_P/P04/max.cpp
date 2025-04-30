//
// Created by tiago-oliveira on 11-03-2025.
//
#include <iostream>
using namespace std;
int max(const int a[], const int n) {
    int mx=a[0];
    for (int i=0; i<n; i++) {
        if (a[i]>mx) mx=a[i];
    }
    return mx;
}
int main () {
    { const int n = 1;
        const int a[n] = { -123 };
        std::cout << max(a,n) << '\n'; }
    { const int n = 3;
        const int a[n] = { -3, -2, -1 };
        std::cout << max(a, n) << '\n'; }
    { const int n = 4;
        const int a[n] = { 4, -2, 3, 1 };
        std::cout << max(a, n) << '\n'; }
    return 0;
}