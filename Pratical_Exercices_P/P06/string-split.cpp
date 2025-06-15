#include <iostream>
#include "print_string.h"
using namespace std;
void split(const string& s, vector<string>& v) {
    unsigned int size=s.length();
    if (size==0) {
        return;
    }
    unsigned int index=0;
    while (index<size) {
        while (index<size && s[index]==' '){
            index++;
        }
        if (index >= size) break;
        unsigned int start = index;
        unsigned int next_space = s.find(' ', index);
        v.push_back(s.substr(start, next_space-start));
        index=next_space;
    }
}


int main () {
    { string s = "";
        vector<string> v;
        split(s, v);
        print(v); }
    { string s = "    ";
        vector<string> v;
        split(s, v);
        print(v); }
    { string s = "  a b  c ";
        vector<string> v;
        split(s, v);
        print(v); }
    { string s = "C++ LEIC FCUP FEUP";
        vector<string> v;
        split(s, v);
        print(v); }
    { string s = "       C++        ";
        vector<string> v;
        split(s, v);
        print(v); }
    return 0;
}