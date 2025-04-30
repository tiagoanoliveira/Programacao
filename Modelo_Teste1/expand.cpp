//
// Created by tiago-oliveira on 17-03-2025.
//
#include "print_array.h"
#include <iostream>
int expand(const int c[], const int v[], int n, int res[], int max) {
    int times = 0;
    int num=0;
    for (int i=0; i<n; i++) {
        times+=c[i];
    }
    if (times>max) return -1;
    for (int j=0; j<n; j++) {
        int round=c[j];
        for (int k=0; k<round; k++) {
            res[num]=v[j];
            num++;
        }
    }
    return num;
}
int main() {
    { const int n = 1;
        const int c[]{3};
        const int v[]{999};
        const int max = 3;
        int res[max] = {0};
        int len = expand(c, v, n, res, max);
        print_array(res, len); }
    return 0;
}