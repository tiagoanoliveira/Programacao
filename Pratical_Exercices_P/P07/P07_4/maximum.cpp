//
// Created by tiago-oliveira on 22-04-2025.
//
#include <cmath>

#include "show_file.h"
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

void maximum(const string& input_fname, const string& output_fname) {
    ifstream in(input_fname);
    string file_line;
    ofstream out(output_fname);
    int count=0;
    double max=-1001.000;
    while (getline(in, file_line)) {
        if (is_valid_line(file_line)) {
            istringstream in_line(file_line);
            while (file_line.back()==' ') {
                file_line.pop_back();
            }
            while (file_line.front()==' ') {
                file_line.erase(0,1);
            }
            double original_value=stod(file_line);
            out << fixed << setprecision(3) << original_value << endl;
            count++;
            if (original_value>max) max=original_value;
        }
    }
    out << "count=" << count << "/max=" << fixed << setprecision(3) << max << endl;
}


int main() {
    { maximum("p4_test1.txt", "p4_test1_out.txt");
        show_file("p4_test1_out.txt"); }
    { maximum("p4_test2.txt", "p4_test2_out.txt");
        show_file("p4_test2_out.txt"); }
    { maximum("p4_test3.txt", "p4_test3_out.txt");
        show_file("p4_test3_out.txt"); }
    { maximum("p4_test4.txt", "p4_test4_out.txt");
        show_file("p4_test4_out.txt"); }
    return 0;
}