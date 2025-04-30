//
// Created by tiago-oliveira on 25-02-2025.
//
#include <iostream>
using namespace std;
void myswap (int &a, int &b) {
    int num=a;
    a=b;
    b=num;
}
int adigits (int a, int b, int c) {
    if (a<b) myswap(a,b);
    if (a<c) myswap(a, c);
    if (b<c) myswap (b,c);
    return a*100+b*10+c;
}
int main() {
    return 0;
}