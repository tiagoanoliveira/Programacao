//
// Created by tiago-oliveira on 20-04-2025.
//
#include <iostream>
char* duplicate(const char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    char* dup = new char[n+1];
    for (int i = 0; i < n; i++) {
        dup[i] = s[i];
    }
    dup[n] = '\0';
    return dup;
}
int main () {
    { char* s = duplicate("");
        std::cout << "\"" << s << "\"\n";
        delete [] s; }
    { char* s = duplicate("a");
        std::cout << "\"" << s << "\"\n";
        delete [] s; }
    { char* s = duplicate("C++");
        std::cout << "\"" << s << "\"\n";
        delete [] s; }
    { char* s = duplicate("0123 456 789 @ abc");
        std::cout << "\"" << s << "\"\n";
        delete [] s; }
}