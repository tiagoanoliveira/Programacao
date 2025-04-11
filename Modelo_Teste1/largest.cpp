//
// Created by tiago-oliveira on 17-03-2025.
//
#include "interval.h"
#include <iostream>
int duration (const interval a) {
    int minutes=0;
    int astarth=a.start.h;
    int astartm=a.start.m;
    int aendh=a.end.h;
    int aendm=a.end.m;
    while (astarth!=aendh || astartm!=aendm) {
        minutes++;
        astartm++;
        if (astartm==60) {
            astarth++;
            astartm=0;
        }
        if (astarth==24) astarth=0;
    }
    return minutes;
}
interval largest(const interval a[], int n) {
    int max=duration(a[0]);
    interval larg=a[0];
    for (int i=1; i<n; i++) {
        if (max<duration(a[i])) {
            max=duration(a[i]);
            larg=a[i];
        }
    }
    return larg;
}
int main () {
    { const int n = 1;
        interval a[n] = {  { { 12, 30 }, { 12, 55 } }  };
        std::cout << largest(a, n) << '\n'; }
    { const int n = 4;
        interval a[n] = {  { { 0,  0  },   { 0,  1 }  },
                           { { 0,  0  },   { 23, 59 } },
                           { { 23, 57 },   { 23, 59 } },
                           { { 0,  1  },   { 23, 59 } } };
        std::cout << largest(a, n) << '\n'; }
    return 0;
}