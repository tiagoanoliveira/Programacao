//
// Created by tiago-oliveira on 17-03-2025.
//
#include <iostream>
using namespace std;
int ssum (int arr[], int n) {
    int maxim=max(arr[0],0);
    int current_max=arr[0];
    for (int i=1; i<n; i++) {
        current_max+=arr[i];
        maxim =max(current_max, maxim);
        if (current_max<0) current_max=0;
    }
    return maxim;
}
int main () {
    { int arr[] = {1, -2, 3, 4, -1};
        std::cout << ssum(arr, 5) << std::endl; }
    { int arr[] = {8};
        std::cout << ssum(arr, 1) << std::endl; }
    { int arr[] = {-1, -1, -1};
        std::cout << ssum(arr, 3) << std::endl; }
    { int arr[] = {10, -1, 20, -21, 4,2,3,7,1};
        std::cout << ssum(arr, 9) << std::endl; }
    return 0;
}