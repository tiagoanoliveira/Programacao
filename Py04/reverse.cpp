//
// Created by tiago-oliveira on 17-03-2025.
//
#include "print_array.h"
#include <iostream>
using namespace std;
void reverse(int arr[], int n) {
    for (int i=0; i<(n/2); i++) {
        int j=n-1-i;
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
int main () {
    { int arr[] = {1, 2, 3, 4, 5};
        reverse(arr, 5);
        print_array(arr, 5); }
    { int arr[] = {999};
        reverse(arr, 1);
        print_array(arr, 1); }
    { int arr[] = {4, 8, 1, 9};
        reverse(arr, 4);
        print_array(arr, 4); }
    return 0;
}