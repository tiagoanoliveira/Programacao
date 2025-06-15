//
// Created by tiago-oliveira on 22-04-2025.
//
#include "smatrix.h"
void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    const int len_a = a.size(), len_b=b.size();
    int index_a=0, index_b=0;
    while (index_a<len_a &&index_b<len_b){
        sm_entry ea=a[index_a];
        sm_entry eb=b[index_b];
        if ( ea.row == eb.row && ea.col == eb.col) {
            // same position, calculate sum of values
            int v = ea.value + eb.value;
            if (v != 0) {
                r.push_back({ ea.row, ea.col, v});
            }
            index_a++;
            index_b++;
        }
        else if (ea.row < eb.row || (ea.row == eb.row && ea.col < eb.col)) {
            // sum entry in a to result
            r.push_back(ea);
            index_a++;
        }
        else {
            // sum entry in b to result
            r.push_back(eb);
            index_b++;
        }
    }
    while (index_a<len_a) {
        r.push_back(a[index_a]);
        index_a++;
    }
    while (index_b<len_b) {
        r.push_back(b[index_b]);
        index_b++;
    }
}
int main () {
    { smatrix r;
        sum({ },
            { {0, 3, 1}, {0, 50, 1} },
            r);
        print(r); }
    { smatrix r;
        sum({ {0, 0, 1}, {1, 0, 1} },
            { {0, 3, 1}, {0, 50, 1} },
            r);
        print(r); }
    { smatrix r;
        sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
            { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
            r);
        print(r); }
    { smatrix r;
        sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
            { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
            r);
        print(r); }
    { smatrix r;
        sum({ {0, 0, -1}, {0, 1, 2},  {5, 10, 20 }, {10, 5, -20} },
            { {0, 0, 1}, {0, 1, -2},  {5, 10, -20}, {10, 5, 20} },
            r);
        print(r); }
    return 0;
}