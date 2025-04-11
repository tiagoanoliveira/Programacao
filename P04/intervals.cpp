//
// Created by tiago-oliveira on 15-03-2025.
//
#include "interval.h"
#include <iostream>
using namespace std;
int interval_duration (const interval b) {
    int minutes=0;
    time_of_day temp=b.start;
    while (temp.h!=b.end.h or temp.m!=b.end.m) {
        minutes++;
        temp.m++;
        if (temp.m==60) {
            temp.h++;
            temp.m=0;
        }
        if (temp.h==24) temp.h=0;
    }
    return minutes;
}
int search_intervals(time_of_day t, const interval a[], int n, interval& u) {
    u={t,t};
    for (int i=0; i<n; i++) {
        if ((a[i].start.h<t.h or (a[i].start.h==t.h and a[i].start.m<=t.m)) and (a[i].end.h>t.h or (a[i].end.h==t.h and a[i].end.m>t.m))) {
            if (a[i].start.h<u.start.h or (a[i].start.h==u.start.h and a[i].start.m<t.m)) {
                u.start=a[i].start;
            }
            if (a[i].end.h>u.end.h or (a[i].end.h==u.end.h and a[i].end.m>u.end.m)) {
                u.end=a[i].end;
            }
        }
    }
    return interval_duration(u);
}

int main () {
    { const int n = 1;
        const time_of_day t = { 13, 00 };
        const interval a[n] { { { 12, 30 }, { 14, 30 } } };
        interval u;
        int d = search_intervals(t, a, n, u);
        std::cout << d << ' ' << u << '\n'; }
    { const int n = 2;
        const time_of_day t = { 14, 30 };
        const interval a[n] { { { 12, 30 }, { 14, 30 } },
                              { { 14, 30 }, { 15, 30 } } };
        interval u;
        int d = search_intervals(t, a, n, u);
        std::cout << d << ' ' << u << '\n'; }
    { const int n = 2;
        const time_of_day t = { 12, 30 };
        const interval a[n] { { { 12, 30 }, { 14, 30 } },
                              { { 14, 30 }, { 15, 30 } } };
        interval u;
        int d = search_intervals(t, a, n, u);
        std::cout << d << ' ' << u << '\n'; }
    { const int n = 2;
        const time_of_day t = { 15, 30 };
        const interval a[n] { { { 12, 30 }, { 14, 30 } },
                              { { 14, 30 }, { 15, 30 } } };
        interval u;
        int d = search_intervals(t, a, n, u);
        std::cout << d << ' ' << u << '\n'; }
    { const int n = 5;
        const time_of_day t = { 15, 15 };
        const interval a[n] { { { 12, 30 }, { 14, 30 } },
                              { { 14, 30 }, { 15, 30 } },
                              { { 15, 10 }, { 16, 10 } },
                              { {  9, 30 }, { 15, 15 } },
                              { {  9, 45 }, { 15, 16 } } };
        interval u;
        int d = search_intervals(t, a, n, u);
        std::cout << d << ' ' << u << '\n'; }
    return 0;
}