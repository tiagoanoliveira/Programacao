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
unsigned long bell(int n){
    if (n==0 or n==1) {
        return 1;
    }
    unsigned long bn = 0;
    for (int k = 0; k < n; k++) {
        bn += bc(n - 1, k) * bell(k);
    }
    return bn;
}
int main() {
    cout << bell(0) << '\n';
    cout << bell(1) << '\n';
    cout << bell(2) << '\n';
    cout << bell(3) << '\n';
    cout << bell(4) << '\n';
    cout << bell(6) << '\n';
    return 0;
}