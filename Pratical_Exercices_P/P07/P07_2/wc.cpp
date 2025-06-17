//
// Created by tiago-oliveira on 22-04-2025.
//
#include "wc.h"
#include <iostream>
using namespace std;
wcresult wc(const string& filename) {
    wcresult final={0,0,0};
    ifstream in(filename);
    string file_line;
    while (getline(in, file_line)) {
        final.lines++;
        final.bytes+=file_line.size();
        istringstream in_line(file_line);
        string current_word;
        while (in_line >> current_word) {
            final.words++;
        }
        final.bytes++;
    }
    return final;
}

int main() {
    { wcresult r = wc("p2_test1.txt");
        std::cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    { wcresult r = wc("p2_test2.txt");
        std::cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    { wcresult r = wc("p2_test3.txt");
        std::cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    { wcresult r = wc("p2_test4.txt");
        std::cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    { wcresult r = wc("p2_test5.txt");
        std::cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    return 0;
}