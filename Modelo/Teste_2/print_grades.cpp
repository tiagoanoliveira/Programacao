#include <iostream>
#include <iomanip>
#include <map>
#include <list>
#include <string>
#include <vector>
#include <algorithm>

void print_grades(const std::map<std::string, std::list<int>>& grades) {
    // Vetor auxiliar para guardar pares {nome, média}
    std::vector<std::pair<std::string, double> > student_averages;

    // Calcular a média de cada aluno e guardar no vetor
    for (std::map<std::string, std::list<int> >::const_iterator it = grades.begin(); it != grades.end(); ++it) {
        const std::string& name = it->first;
        const std::list<int>& lst = it->second;

        double sum = 0.0;
        for (std::list<int>::const_iterator jt = lst.begin(); jt != lst.end(); ++jt)
            sum += *jt;
        double avg = lst.empty() ? 0.0 : sum / lst.size();

        student_averages.push_back(std::make_pair(name, avg));
    }

    // Ordenar por média decrescente
    std::sort(student_averages.begin(), student_averages.end(),
        // lambda com tipos explícitos!
        [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
            return a.second > b.second;
        });

    // Preparar para imprimir com 2 casas decimais
    std::cout << std::fixed << std::setprecision(2);

    // Imprimir cada aluno e respetiva média
    double overall_sum = 0.0;
    for (std::vector<std::pair<std::string, double> >::const_iterator it = student_averages.begin(); it != student_averages.end(); ++it) {
        std::cout << it->first << ' ' << it->second << '\n';
        overall_sum += it->second;
    }

    // Imprimir a média global das médias
    double overall_avg = student_averages.empty() ? 0.0 : overall_sum / student_averages.size();
    std::cout << overall_avg << '\n';
}

int main () {
    print_grades( {{"Jerry", {10, 20, 15}}} );
    print_grades( {{"Elaine", {15, 18, 14, 16}}, {"Newman", {18, 12, 19 }}} );
    print_grades( {{"Whatley", {10, 10}}, {"Kramer", {11, 12, 14}}, {"Cosmo", { 15, 10, 13}}} );
    print_grades( {{"Costanza", {0, 11}}, {"Frank", {8, 12}}} );
    print_grades ( {{"Frank", {10, 15}}, {"Costanza", {10, 14}}} );
    return 0;
}