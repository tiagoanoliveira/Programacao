/*
Created by tiago-oliveira on 18-02-2025.

In number theory, a pernicious number is a positive integer that has a prime number of 1s in their binary representation. We are interested in numbers that are both prime and pernicious. For instance 7=1112 is both prime and pernicious, 6=1102 is pernicious but not prime, and 23=10111(2) is prime but not pernicious.

Write a C++ program that prints the value of all numbers between a and b that are both pernicious and prime, where a and b are positive integers supplied as input.

Hint:
    If you developed an is_prime() function in the previous exercise, it can also help you here;
    The shift right operator >> might help you in counting the number of 1s in the binary representation;
*/

#include <iostream>
using namespace std;
bool is_prime (int n) {
    if (n==1) return false;
    for (int i=2; i<n; i++){
        if (n%i==0) {
            return false;
        }
    }
    return true;
}
int count_ones(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int main() {
    int a, b;
    cin >> a >> b;
    for (int num = a; num <= b; ++num) {
        if (is_prime(num) && is_prime(count_ones(num))) {
            cout << num << " ";
        }
    }
    cout << endl;
    return 0;
}