//
// Created by tiago-oliveira on 11-04-2025.
//
#include <iostream>
#include "cdata.h"
using namespace std;
int* expand_cdata(const cdata a[], int n) {
    // iterar sobre o a e somar os values
    int nv=0;
    for (int i=0; i<n; i++) {
        nv+=a[i].count;
    }
    int* res = new int[nv];
    int index=0;
    int j=0;
    for (int k=0; k<n; k++) {
        int times=a[j].count;
        for (int l=0; l<times; l++) {
            res[index]=a[j].value;
            index++;
        }
        j++;
    }
    return res;
}




int main () {
    { const int n = 1;
        const cdata a[] { { 3, 999 } };
        int* r = expand_cdata(a, n);
        print_array(r, 3);
        delete [] r; }
    { const int n = 3;
        const cdata a[] { { 3, 100 }, { 2, 200 }, { 1, 300 } };
        int* r = expand_cdata(a, n);
        print_array(r, 6);
        delete [] r; }
    { const int n = 1;
        const cdata a[] { { 1, 999 } };
        int* r = expand_cdata(a, n);
        print_array(r, 1);
        delete [] r; }
    { const int n = 2;
        const cdata a[] { { 20, 1 }, { 17, 2} };
        int* r = expand_cdata(a, n);
        print_array(r, 37);
        delete [] r; }
    { const int n = 4;
        const cdata a[] { { 2, 5 }, { 1, 2 }, { 3, 0 }, { 7, -1 } };
        int* r = expand_cdata(a, n);
        print_array(r, 13);
        delete [] r; }
    return 0;
}