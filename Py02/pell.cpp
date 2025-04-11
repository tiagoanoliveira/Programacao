//
// Created by tiago-oliveira on 16-03-2025.
//
#include <iostream>
using namespace std;
unsigned long pell (unsigned long n) {
    unsigned long pn2=0, pn1=1, pn;
    if (n==0) return pn2;
    if (n==1) return pn1;
    for (unsigned long i=2; i<=n; i++) {
        pn=2*pn1+pn2;
        pn2=pn1;
        pn1=pn;
    }
    return pn;
}
int main () {
    std::cout << pell(0) << '\n';
    std::cout << pell(1) << '\n';
    std::cout << pell(2) << '\n';
    std::cout << pell(3) << '\n';
    std::cout << pell(5) << '\n';
    std::cout << pell(50) << '\n';
    return 0;
}