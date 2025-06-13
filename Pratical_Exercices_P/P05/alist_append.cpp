//
// Created by tiago-oliveira on 20-04-2025.
//
#include <iostream>
#include "alist.h"
using namespace std;
void append(alist* a, const alist* b) {
    if (b->size==0) return;
    const int a_len = a->size;
    a->size+=b->size;
    int* tmp = new int[a->size];
    if (a_len==0) a->elements=tmp;
    else {
        copy(a->elements, a->elements+a_len, tmp);
        delete[] a->elements;
        a->elements=tmp;
    }
    for (int i=0; i<b->size; i++) {
        a->elements[i+a_len]=b->elements[i];
    }
}

int main() {
    { alist* a = empty();
        const alist* b = empty();
        append(a, b);
        print(a);
        destroy(a);
        destroy(b); }
    { alist* a = empty();
        const int nB = 2;
        int eB[nB] = { 1, 2 };
        const alist* b = build(nB, eB);
        append(a, b);
        print(a);
        destroy(a);
        destroy(b); }
    { const int nA = 2;
        int eA[nA] = { 1, 2 };
        alist* a = build(nA, eA);
        const alist* b = empty();
        append(a, b);
        print(a);
        destroy(a);
        destroy(b); }
    { const int nA = 2;
        int eA[nA] = { 1, 2 };
        alist* a = build(nA, eA);
        const int nB = 3;
        int eB[nB] = { 3, 4, 5 };
        const alist* b = build(nB, eB);
        append(a, b);
        print(a);
        destroy(a);
        destroy(b); }
    { const int nA = 4;
        int eA[nA] = { 1, 2, 3, 4 };
        alist* a = build(nA, eA);
        const int nB = 3;
        int eB[nB] = { 5, 6, 7 };
        const alist* b = build(nB, eB);
        append(a, b);
        print(a);
        destroy(a);
        destroy(b); }
    return 0;
}