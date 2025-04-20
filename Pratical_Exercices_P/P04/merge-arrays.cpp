//
// Created by tiago-oliveira on 11-03-2025.
//
#include <iostream>
#include "print_array.h"
using namespace std;
void merge_arrays(const int a[], const int NA, const int b[], const int NB, int c[]) {
    int i_a=0;
    int i_b=0;
    for (int j=0; j<(NA+NB); j++) {
        if (i_a<NA && i_b<NB) {
            if (a[i_a]<b[i_b]) {
                c[j]=a[i_a];
                i_a++;
            }
            else {
                c[j]=b[i_b];
                i_b++;
            }
        }
        else if (i_a<NA) {
            c[j]=a[i_a];
            i_a++;
        }
        else {
            c[j]=b[i_b];
            i_b++;
        }
    }
}
int main() {
    { const int NA = 4, NB = 6;
        int a[NA] = { 1, 2, 4, 7};
        int b[NB] = { 0, 3, 5, 6, 8, 9};
        int c[NA+NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA+NB); }
    { const int NA = 6, NB = 4;
        int a[NA] = { 0, 3, 5, 6, 8, 9};
        int b[NB] = { 1, 2, 4, 7};
        int c[NA+NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA+NB); }
    { const int NA = 2, NB = 3;
        int a[NA] = { 0, 1 };
        int b[NB] = { 2, 3, 4 };
        int c[NA+NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA+NB); }
    { const int NA = 3, NB = 2;
        int a[NA] = { 2, 3, 4 };
        int b[NB] = { 0, 1 };
        int c[NA+NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA+NB); }
    { const int NA = 15, NB = 15;
        int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
        int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
        int c[NA+NB];
        merge_arrays(a, NA, b, NB, c);
        print_array(c, NA+NB); }
    return 0;
}