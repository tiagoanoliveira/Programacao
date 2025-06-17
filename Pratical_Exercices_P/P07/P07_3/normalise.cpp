//
// Created by tiago-oliveira on 22-04-2025.
//
#include "print.h"
using namespace std;
bool is_valid_line (const string& current_line) { //confirmar se não é uma linha vazia ou apenas com espaços
    if (current_line.empty()) return false;
    for (const char c: current_line) {
        if (c!=' ') {
            return true;
        }
    }
    return false;
}

string to_upper(const string& s) {
    string upper_str;
    for (char c:s) {
        upper_str+=toupper(c);
    }
    return upper_str;
}

void normalise(const string& input_fname, const string& output_fname) {
    ifstream in(input_fname);
    string file_line;
    ofstream out(output_fname);
    while (getline(in, file_line)) {
        istringstream in_line(file_line);
        if (is_valid_line(file_line)) {
            while (file_line.back()==' ') {
                file_line.pop_back();
            }
            while (file_line.front()==' ') {
                file_line.erase(0,1);
            }
            out << to_upper(file_line) << endl;
        }
    }
}

int main() {
    { normalise("p3_test1.txt", "p3_test1_out.txt");
        print("p3_test1_out.txt"); }
    { normalise("p3_test2.txt", "p3_test2_out.txt");
        print("p3_test2_out.txt"); }
    { normalise("p3_test3.txt", "p3_test3_out.txt");
        print("p3_test3_out.txt"); }
    { normalise("p3_test4.txt", "p3_test4_out.txt");
        print("p3_test4_out.txt"); }
    { normalise("p3_test5.txt", "p3_test5_out.txt");
        print("p3_test5_out.txt"); }
    return 0;
}