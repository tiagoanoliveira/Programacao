//
// Created by tiago-oliveira on 22-02-2025.
//
#include <iostream>
using namespace std;
int main () {
    float a,b;
    char op;
    cin >> a >> op >> b;
    switch (op) {
        case '+':
            cout << (a+b);
            break;
        case '-':
            cout << (a-b);
            break;
        case '*':
            cout << (a*b);
            break;
        case '/':
            if (b==0) {
                cout << "invalid operand: divisor cannot be 0";
                break;
            }
            cout << a/b;
            break;
        default:
            cout << "invalid operation";
            break;
    }
    return 0;
}