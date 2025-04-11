//
// Created by tiago-oliveira on 11-03-2025.
//
#include <iostream>
using namespace std;
unsigned long hstr_to_integer(const char hstr[]) {
    unsigned long result = 0;
    for (int i = 0; hstr[i] != '\0'; i++) {
        char c = hstr[i];
        unsigned int digit;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digit = 10 + (c - 'A');
        } else if (c >= 'a' && c <= 'f') {
            digit = 10 + (c - 'a');
        }
        result = (result << 4) | digit;
    }
    return result;
}
int main() {
    std::cout << hstr_to_integer("0");
    std::cout << hstr_to_integer("A");
	std::cout << hstr_to_integer("19");
    std::cout << hstr_to_integer("fF");
    std::cout << hstr_to_integer("CafeBabe2022");
    return 0;
}