//
// Created by tiago-oliveira on 16-03-2025.
//
#include <iostream>
using namespace std;
bool leap (int year) {
    if (year%100==0 && year%400!=0) return false;
    if (year%4==0) return true;
    return false;
}
int days (int year) {
    int total=0;
    for (int i=1900; i<=year; i++) {
        if (leap(i)) total+=366;
        else total+=365;
    }
    return total;
}
int sundays (int year) {
    return days(year)/7;
}
int main () {
    std::cout << sundays(1900) << '\n';
    std::cout << sundays(1950) << '\n';
    std::cout << sundays(2000) << '\n';
    std::cout << sundays(2025) << '\n';
    return 0;
}

