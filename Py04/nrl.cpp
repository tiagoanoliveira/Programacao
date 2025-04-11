//
// Created by tiago-oliveira on 18-03-2025.
//
#include <iostream>
using namespace std;
int nrl(const char s[], char low[]) {
    int let[26]={0};
    for (int i=0; s[i]!='\0'; i++) {
        char c=s[i];
        if (c>='a' && c<='z') let[c-'a']++;
        if (c>='A' && c<='Z') let[c-'A']++;
    }
    int counter=0;
    for (int i=0; i<26; i++) {
        if (let[i]==1) {
            low[counter]='a'+i;
            counter++;
        }
    }
    if (counter==0) low[0]=*"";
    return counter;

}
int main () {
    { const char s[] = "";
        char l[27] = { -1 };
        int r = nrl(s, l);
        std::cout << '\"' << s << "\" "
                  << r << " \"" << l << "\"\n"; }
    { const char s[] = "  F C U P  F E U P  Porto  ";
        char l[27] = { -1 };
        int r = nrl(s, l);
        std::cout << '\"' << s << "\" "
                  << r << " \"" << l << "\"\n"; }
    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
        char l[27] = { -1 };
        int r = nrl(s, l);
        std::cout << '\"' << s << "\" "
                  << r << " \"" << l << "\"\n"; }
    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz";
        char l[27] = { -1 };
        int r = nrl(s, l);
        std::cout << '\"' << s << "\" "
                  << r << " \"" << l << "\"\n"; }
    { const char s[] = "The quick brown fox jumps over the lazy dog";
        char l[27] = { -1 };
        int r = nrl(s, l);
        std::cout << '\"' << s << "\" "
                  << r << " \"" << l << "\"\n"; }
    return 0;
}