//
// Created by tiago-oliveira on 23-02-2025.
//
#include <iostream>
using namespace std;
int main () {
    char in, out;
    cin >> in >> out;
    int key = in ^ out;
    cout << "encryption key is " << key;
    return 0;
}