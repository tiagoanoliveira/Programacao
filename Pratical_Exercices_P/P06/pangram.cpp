//
// Created by tiago-oliveira on 20-04-2025.
//
#include <iostream>
using namespace std;
bool pangram(const string& s, string& m) {
    bool letters[26]={false};
    for (char c:s) {
        if (c==' ') continue;
        letters[tolower(c)-'a']=true;
    }
    m="";
    bool is_pangram=true;
    for (int i =0; i<26; i++) {
        if (!letters[i]) {
            is_pangram=false;
            m+=(char)('a'+i);
        }
    }
    return is_pangram;
}
int main() {
    { string s = "";
        string m = "";
        bool r = pangram(s, m);
        std::cout << '\"' << s << "\" "
                  << boolalpha << r << " \"" << m << "\"\n"; }
    { string s = "The quick brown fox jumps over the lazy dog";
        string m = "";
        bool r = pangram(s, m);
        std::cout << '\"' << s << "\" "
                  << boolalpha << r << " \"" << m << "\"\n"; }
    { string s = "A quick brown fox jumps over a classy dog";
        string m = "";
        bool r = pangram(s, m);
        std::cout << '\"' << s << "\" "
                  << boolalpha << r << " \"" << m << "\"\n"; }
    { string s = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
        string m = "";
        bool r = pangram(s, m);
        std::cout << '\"' << s << "\" "
                  << boolalpha << r << " \"" << m << "\"\n"; }
    { string s = " Stu yZ abC GhI MnO pQr   ";
        string m = "";
        bool r = pangram(s, m);
        std::cout << '\"' << s << "\" "
                  << boolalpha << r << " \"" << m << "\"\n"; }
    return 0;
}