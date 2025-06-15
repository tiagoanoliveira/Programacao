//
// Created by tiago-oliveira on 22-04-2025.
//
#include <iostream>
#include <vector>
using namespace std;
struct smallest_string{
    string small_string;
    unsigned short len;
};
smallest_string len_strings(const vector<string>& v) {
    smallest_string smallest{v[0], static_cast<unsigned short>(v[0].size())};
    unsigned short current_index= 0;
    for (string s:v) {
        unsigned short current_len=s.size();
        if (current_len<smallest.len) {
            smallest.len=current_len;
            smallest.small_string=s;
        }
        current_index++;
    }
    return smallest;
}
string longest_prefix(const vector<string>& v) {
    smallest_string smallest=len_strings(v);
    for (string s : v) {
        unsigned short index=0;
        while (index<smallest.len) {
            if (smallest.small_string[index]!=s[index]) {
                smallest.len=index;
                smallest.small_string=s.substr(0, smallest.len);
                break;
            }
            index++;
        }
    }
    return smallest.small_string;
}
int main () {
    std::cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";
    std::cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";
    std::cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek",  }) << "\"\n";
    std::cout << "\"" << longest_prefix({ "sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations" }) << "\"\n";
    std::cout << "\"" << longest_prefix({ "symmetricstalwartscorn'flowers", "symmetricShetland'ssuccessfully", "symmetricreceiver'shipsteed", "symmetricGrailsflown", "symmetricpromenadingoutflank", "symmetricdrugg'ingseizure", "symmetricsanctumsove'rprinting", "symmetricCitroentransgr'essed", "symmetricdissembledwinging", "symmetric'recoupingCinderella" }) << "\"\n";
    return 0;
}