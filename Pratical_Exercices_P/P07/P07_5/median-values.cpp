//
// Created by tiago-oliveira on 22-04-2025.
//
#include "show_file.h"
using namespace std;
bool is_valid_line (const string& current_line) {
    //confirmar se não é um comentário
    if (current_line[0]=='#') return false;
    return true;
}

void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream in(input_fname);
    string file_line;
    ofstream out(output_fname);
    while (getline(in, file_line)) {
        if (is_valid_line(file_line)) {
            int count=0;
            double median;
            vector<double> numbers;
            bool first_line=true;
            istringstream in_line(file_line);
            string current_word;
            while (in_line >> current_word) {
                if (first_line) {
                    first_line=false;
                    out << current_word << ' ';
                }
                else {
                    numbers.push_back(stod(current_word));
                    count++;
                }
            }
            sort(numbers.begin(), numbers.end());
            if (count%2!=0) median=numbers[count/2];
            else median=((numbers[count/2-1]+numbers[count/2])/2);
            out << fixed << setprecision(1) << median << endl;
        }
    }
}

int main () {
    { calc_medians("p5_test1.txt", "p5_test1_out.txt");
        show_file("p5_test1_out.txt"); }
    { calc_medians("p5_test2.txt", "p5_test2_out.txt");
        show_file("p5_test2_out.txt"); }
    { calc_medians("p5_test3.txt", "p5_test3_out.txt");
        show_file("p5_test3_out.txt"); }
    { calc_medians("p5_test4.txt", "p5_test4_out.txt");
        show_file("p5_test4_out.txt"); }
    { calc_medians("p5_test5.txt", "p5_test5_out.txt");
        show_file("p5_test5_out.txt"); }
    return 0;
}