//
// Created by tiago-oliveira on 17-03-2025.
//
#include "print_array.h"
#include <iostream>
using namespace std;
void change (int a[], const int n) {
    const int first=a[0];
    for (int i=0; i<(n-1); i++) {
        a[i]=a[i+1];
    }
    a[n-1]=first;
}
void rotate_left(int a[], int n, int k) {
    for (int i=0; i<k; i++) {
        change(a, n);
    }
}
int main () {
    { int a[] = { 1, 2, 3, 4, 5 };
        int size = sizeof(a) / sizeof(int);
        rotate_left(a, size, 1);
        print_array(a, size); }
    { int a[] = { 1, 2, 3, 4, 5 };
        int size = sizeof(a) / sizeof(int);
        rotate_left(a, size, 2);
        print_array(a, size); }
    { int a[] = { 1, 2, 3, 4, 5 };
        int size = sizeof(a) / sizeof(int);
        rotate_left(a, size, -1);
        print_array(a, size); }
    { int a[] = { 10, 20, 30, 40 };
        int size = sizeof(a) / sizeof(int);
        rotate_left(a, size, 4);
        print_array(a, size); }
    { int a[] = { -3, -5, -7 };
        int size = sizeof(a) / sizeof(int);
        rotate_left(a, size, 5);
        print_array(a, size); }
    return 0;
}