//
// Created by tiago-oliveira on 18-03-2025.
//
#include <iostream>
using namespace std;
void trim(char s[]) {
    int start=0;
    int end=0;
    for (int i=0; s[i]!='\0'; i++) end++;
    while (s[start]==' ') {
        start++;
    }
    while (end> start && s[end-1]==' ') {
        end--;
    }
    int leng=end-start;
    for (int i=0; i<leng; i++) {
        s[i]=s[start];
        start++;
    }
    s[leng]='\0';
}

int main () {
    { char s[] = " abc! def? ";
        std::cout << "\"" << s << "\" => ";
        trim(s);
        std::cout << "\"" << s << "\"\n"; }
    { char s[] = "#abc";
        std::cout << "\"" << s << "\" => ";
        trim(s);
        std::cout << "\"" << s << "\"\n"; }
    { char s[] = "    abc def";
        std::cout << "\"" << s << "\" => ";
        trim(s);
        std::cout << "\"" << s << "\"\n"; }
    { char s[] = "abc def.   ";
        std::cout << "\"" << s << "\" => ";
        trim(s);
        std::cout << "\"" << s << "\"\n"; }
    { char s[] = "   ";
        std::cout << "\"" << s << "\" => ";
        trim(s);
        std::cout << "\"" << s << "\"\n"; }
    { char s[] = "";
        std::cout << "\"" << s << "\" => ";
        trim(s);
        std::cout << "\"" << s << "\"\n"; }
    { char s[] = " abc  _  def  _  ghi ";
        std::cout << "\"" << s << "\" => ";
        trim(s);
        std::cout << "\"" << s << "\"\n"; }
    { char s[] = "a           ";
        std::cout << "\"" << s << "\" => ";
        trim(s);
        std::cout << "\"" << s << "\"\n"; }
    return 0;
}