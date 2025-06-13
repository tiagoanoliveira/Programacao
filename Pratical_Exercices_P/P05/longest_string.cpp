//
// Created by tiago-oliveira on 22-04-2025.
//
#include <iostream>
using namespace std;
const char* longest(const char* pa[]) {
    int n, i=0;
    int max=0;
    while (pa[i]!=nullptr) {
        int len=0;
        while (pa[i][len]!='\0') len++;
        if (len>=max) {
            max=len;
            n=i;
        }
        i++;
    }
    return pa[n];
}

int main () {
    { const char* pa[] = { "C++", nullptr };
        std::cout << "\"" << longest(pa) << "\"\n"; }
    { const char* pa[] = { "", "0123", "Hello", "world", "!", nullptr };
        std::cout << "\"" << longest(pa) << "\"\n"; }
    { const char* pa[]  = { "Hello_world", "Hello", "Hello world", nullptr };
        std::cout << "\"" << longest(pa) << "\"\n"; }
    { const char* pa[] = { "Hello world!", "Hello_world", "Hello world", nullptr };
        std::cout << "\"" << longest(pa) << "\"\n"; }
    { const char* pa[] = { "C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "Typescript", "OCaml", "Fortran", nullptr };
        std::cout << "\"" << longest(pa) << "\"\n"; }
    return 0;
}