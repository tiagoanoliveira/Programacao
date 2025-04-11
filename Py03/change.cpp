//
// Created by tiago-oliveira on 16-03-2025.
//
#include "amount.h"
#include <iostream>
using namespace std;
amount change(amount given, amount price) {
    amount cash;
    cash.euros=given.euros-price.euros;
    cash.cents=given.cents-price.cents;
    if (cash.cents<0) {
        cash.cents+=100;
        cash.euros--;
    }
    return cash;
}
int main() {
    { amount a({5, 50}); amount b({2, 30});
        std::cout << change(a, b) << '\n'; }
    { amount a({5, 50}); amount b({5, 50});
        std::cout << change(a, b) << '\n'; }
    { amount a({0, 0}); amount b({0, 0});
        std::cout << change(a, b) << '\n'; }
    return 0;
}