//
// Created by tiago-oliveira on 17-03-2025.
//
#include "print_array.h"
#include <iostream>
using namespace std;
void build(int arr[], int n) {
    for (int i=1; i<n; i++) {
        arr[i]+=arr[i-1];
    }
}
int sum(int arr[], int a, int b) {
    if (a==0) return arr[b];
    return arr[b]-arr[a-1];
}
int main () {
    { int arr[] = {1, -2, 3, 4, -1};
        build(arr, 5);
        print_array(arr, 5); }
    { int arr[] = {1};
        build(arr, 1);
        print_array(arr, 1); }
    {  int arr[] = {-1, 5, -7};
        std::cout << sum(arr, 0, 2) << " " << sum(arr, 0, 0) << " " << sum(arr, 1, 2) << std::endl; }
    { int arr[] = {3, 5, 8, 10};
        std::cout << sum(arr, 0, 2) << " " << sum(arr, 3, 3) << " " << sum(arr, 1, 2) << std::endl; }
    return 0;
}