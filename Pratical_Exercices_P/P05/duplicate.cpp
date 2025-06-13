//
// Created by tiago-oliveira on 20-04-2025.
//
#include <iostream>
using namespace std;
char* duplicate(const char s[]) {
    int len =0;
    while (s[len]!='\0') len++;
    char *dup = new char[len+1];
    copy(s, s+len, dup);
    dup[len]='\0';
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
    return 0;
}