#include "show_file.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void word_count(const std::string& input_fname, const std::string& output_fname) {
    std::ifstream infile(input_fname);
    std::ofstream outfile(output_fname);

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string word;
        int count = 0;

        // Conta palavras separadas por espaço
        while (iss >> word) {
            ++count;
        }

        // Escreve a contagem no ficheiro de saída
        outfile << count << '\n';
    }
}

int main () {
    { word_count("f1.txt", "f1_out.txt");
        show_file("f1_out.txt"); }
    { word_count("f2.txt", "f2_out.txt");
        show_file("f2_out.txt"); }
    return 0;
}