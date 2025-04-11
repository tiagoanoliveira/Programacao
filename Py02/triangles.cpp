//
// Created by tiago-oliveira on 16-03-2025.
//
#include <iostream>
using namespace std;
int triangles (int p) {
    int count=0;
    for (int a = 1; a < p / 2; ++a) {
        for (int b = a; b < p / 2; ++b) {
            int c = p - a - b; // Compute c
            if (a * a + b * b == c * c) { // Check Pythagorean theorem
                count++;
            }
        }
    }
    return count;
}
int main () {
    std::cout << triangles(120) << '\n';
    std::cout << triangles(12) << '\n';
    std::cout << triangles(960) << '\n';
    std::cout << triangles(5) << '\n';
    return 0;
}