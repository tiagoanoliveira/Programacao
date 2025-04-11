//
// Created by tiago-oliveira on 15-03-2025.
//
#include <iostream>
using namespace std;
unsigned long next_mersenne(unsigned long n) {
    unsigned long mers=0;
    for (unsigned long i=1; i<=n; i++) {
        mers=mers*2+1;
        if (mers>=n) return mers;
    }
    return mers;
}
int main () {
    std::cout << next_mersenne(0) << '\n';
    std::cout << next_mersenne(1) << '\n';
    std::cout << next_mersenne(2) << '\n';
    std::cout << next_mersenne(4) << '\n';
    std::cout << next_mersenne(128) << '\n';
    std::cout << next_mersenne(4294967296UL) << '\n';
    return 0;
}