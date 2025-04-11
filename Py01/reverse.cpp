//
// Created by tiago-oliveira on 23-02-2025.
//
#include <iostream>
using namespace std;
int main() {
    int num, final=0;
    cin >> num;
    while (num!=0) {
        int a = num % 10;
        final=final*10+a;
        num/=10;
    }
    cout << final;
    return 0;
}