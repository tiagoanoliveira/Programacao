//
// Created by tiago-oliveira on 18-02-2025.
//
#include <iostream>
#include <cmath>
using namespace std;
bool is_prime (int n) {
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0) {
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    for (int i=2; i<=n; i++){
        if (is_prime(i)) {
            cout << i << ' ';
        }
    }
    return 0;
}