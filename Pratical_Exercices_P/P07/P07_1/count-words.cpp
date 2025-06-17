//
// Created by tiago-oliveira on 22-04-2025.
//
#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;
string to_lower(const string& s) {
    string lower_str;
    for (char c:s) {
        lower_str+=tolower(c);
    }
    return lower_str;
}

int count(const string& fname, const string& word) {
    ifstream in(fname);
    string target=to_lower(word);
    int counter=0;
    string file_word;
    while (in >> file_word) {
        if (to_lower(file_word)==target) counter++;
    }
    return counter;
}
int main() {
    std::cout << count("p1_test_a.txt", "THE") << '\n';
    std::cout << count("p1_test_a.txt", "0") << '\n';
    std::cout << count("p1_test_a.txt", "code") << '\n';
    std::cout << count("p1_test_b.txt", "Collider") << '\n';
    std::cout << count("p1_test_b.txt", "you") << '\n';
    return 0;
}