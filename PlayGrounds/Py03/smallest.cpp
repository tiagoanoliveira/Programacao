//
// Created by tiago-oliveira on 16-03-2025.
//
#include "interval.h"
#include <iostream>
using namespace std;
int duration(interval n) {
    int minutes=0;
    while (n.start.m!=n.end.m || n.start.h!=n.end.h) {
        minutes++;
        n.start.m++;
        if (n.start.m==60) {
            n.start.m=0;
            n.start.h++;
        }
        if (n.start.h==24) n.start.h=0;
    }
    return minutes;
}
interval smallest(const interval a[], int n) {
    interval small= a[0];
    int smduration=duration(small);
    for (int i=1; i<n; i++) {
        if (duration(a[i])<smduration) {
            small=a[i];
            smduration=duration(a[i]);
        }
    }
    return small;
}
int main () {
    { const int n = 1;
        interval a[n] = { { { 12, 30 }, { 12, 55 } } };
        std::cout << smallest(a, n) << '\n'; }
    { const int n = 4;
        interval a[n] = {  { { 0,  0  },   { 0,  1 }  },
                           { { 0,  0  },   { 23, 59 } },
                           { { 23, 57 },   { 23, 59 } },
                           { { 0,  1  },   { 23, 59 } } };
        std::cout << smallest(a, n) << '\n'; }
    { const int n = 5;
        interval a[n] = {  { { 0,  1 }, {  23, 59 } },
                           { { 0,  2 }, {  23, 59 } },
                           { { 0,  2 }, {  23, 58 } },
                           { { 0,  0 }, {  23, 59 } },
                           { { 0,  0 }, {  23, 58 } } };
        std::cout << smallest(a, n) << '\n'; }
    { const int n = 5;
        interval a[n] = {  { { 12,  59 }, { 13, 4  } },
                           { { 0,   0  }, { 0,  4  } },
                           { { 23,  53 }, { 23, 54 } },
                           { { 13,  29 }, { 13, 31 } },
                           { { 18,  59 }, { 19, 2  } } };
        std::cout << smallest(a, n) << '\n'; }
    { const int n = 5;
        interval a[n] = {  { { 12,  59 }, { 13, 4  } },
                           { { 0,   0  }, { 0,  4  } },
                           { { 23,  53 }, { 23, 59 } },
                           { { 13,  29 }, { 13, 36 } },
                           { { 18,  58 }, { 19, 0  } } };
        std::cout << smallest(a, n) << '\n'; }
    return 0;
}