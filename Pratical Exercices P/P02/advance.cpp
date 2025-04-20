//
// Created by tiago-oliveira on 25-02-2025.
//
#include <iostream>
using namespace std;
bool is_leap_year(int y) {
    return (y % 4 == 0 &&
    y % 100 != 0) ||
    y % 400 == 0;
}
int days_in_month(int m, int y) {
    int d;
    switch (m) {
        case 2: // February
            d = is_leap_year(y) ? 29 : 28; break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: // 31 days
        d = 31; break;
        default: // All other months have 30 days
            d = 30; break;
    }
    return d;
}
void advance(int delta, int& d, int& m, int& y) {
    while (delta>0){
        int days_month=days_in_month(m, y);
        if (d+delta<=days_month) {
            d+=delta;
            break;
        }
        delta-=(days_month-d+1);
        d=1;
        m++;
        if (m>12) {
            m=1;
            y++;
        }
    }
}

int main() {
    int d = 2, m = 12, y = 1900;
    advance(365 + 5, d, m, y);
    std::cout << d << ' ' << m << ' ' << y << '\n';
    return 0;
}