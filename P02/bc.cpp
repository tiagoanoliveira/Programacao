//
// Created by tiago-oliveira on 25-02-2025.
//
#include <iostream>
using namespace std;
unsigned long factorial(unsigned long n) {
    unsigned long factorial=1;
    for (unsigned long i=1; i<=n; i++) {
        factorial*=i;
    }
    return factorial;
}
unsigned long bc(unsigned long n, unsigned long k) {
    return factorial(n)/(factorial(k)*factorial(n-k));
}
int main () {
    cout << bc(5, 0) << '\n';
    cout << bc(5, 1) << '\n';
    cout << bc(5, 5) << '\n';
    cout << bc(5, 2) << '\n';
    cout << bc(12, 7) << '\n';
    cout << bc(20, 10) << '\n';
    return 0;
}