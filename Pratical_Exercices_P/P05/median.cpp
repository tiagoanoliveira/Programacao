//
// Created by tiago-oliveira on 20-04-2025.
//
#include <iostream>
#include <algorithm>
using namespace std;
int median(const int a[], int n) {
    int *tmp = new int[n];
    copy(a, a+n, tmp);
    sort(tmp, tmp+n);
    int median = tmp[n/2];
    if (n%2==0) median=(tmp[n/2-1] + tmp[n/2])/2;
    delete [] tmp;
    return median;
}
int main () {
    { const int n = 5;
        int a[n] { 10, -10, 0, 12, 11 };
        std::cout << median(a, n) << '\n'; }
    { const int n = 6;
        int a[n] { 30, 10, 0, -20, 14, 20 };
        std::cout << median(a, n) << '\n'; }
    { const int n = 1;
        int a[n] { 99 };
        std::cout << median(a, n) << '\n'; }
    { const int n = 2;
        int a[n] { 101, 99 };
        std::cout << median(a, n) << '\n'; }
    return 0;
}