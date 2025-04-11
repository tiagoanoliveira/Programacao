//
// Created by tiago-oliveira on 09-03-2025.
//
#include <iostream>
#include "time_of_day.h"
using namespace std;
time_of_day tick(time_of_day t) {
    t.m++;
    if (t.m==60) {
        t.m=0;
        t.h+=1;
    }
    if (t.h==24) t.h=0;
    return {t.h, t.m};
}

int main () {
    std::cout << tick({ 0, 0 }) << '\n';
    std::cout << tick({ 12, 30 }) << '\n';
    std::cout << tick({ 12, 59 }) << '\n';
    std::cout << tick({ 23, 59 }) << '\n';
    std::cout << tick(tick(tick({ 23, 59 }))) << '\n';
    return 0;
}