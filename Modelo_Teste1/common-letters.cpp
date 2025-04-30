//
// Created by tiago-oliveira on 17-03-2025.
//
#include <iostream>
using namespace std;
int common_letters(const char a[], const char b[], char out[]) {
    int found_a[26]={0};
    int found_b[26]={0};
    for (int i=0; a[i]!='\0'; i++) {
        char c=a[i];
        if (c>='A' && c<='Z') found_a[c-'A']=1;
        if (c>='a'&& c<='z') found_a[c-'a']=1;
    }
    for (int i=0; b[i]!='\0'; i++) {
        char c=b[i];
        if (c>='A' && c<='Z') found_b[c-'A']=1;
        if (c>='a'&& c<='z') found_b[c-'a']=1;
    }
    int counter=0;
    for (int i=0; i<26; i++) {
        if (found_a[i]==found_b[i] && found_a[i]==1) {
            out[counter]='a'+i;
            counter++;
        }
    }
    out[counter]='\0';
    return counter;
}
int main () {
    { char out[26+1];
        int n = common_letters("+LEIC", "c++", out);
        std::cout << n << " \"" << out << "\"\n"; }
    { char out[26+1];
        int n = common_letters("LEIC @ UP", "XY ZZZ++", out);
        std::cout << n << " \"" << out << "\"\n"; }
    { char out[26+1];
        int n = common_letters("", "abcdefghi JKLMNOPQRSTUVWXyz", out);
        std::cout << n << " \"" << out << "\"\n"; }
    { char out[26+1];
        int n = common_letters("JKLMNOPQRSTUVWXyz ABCDE fghi", "abcdefghi JKLMNOPQRSTUVWXyz", out);
        std::cout << n << " \"" << out << "\"\n"; }
    { char out[26+1];
        int n = common_letters("J LMNOP RSTUVWXyz ABCDE fghi", "a cdefghi JKL NOPQRS UVWXy", out);
        std::cout << n << " \"" << out << "\"\n"; }
    { char out[26+1];
        int n = common_letters("abcdefgh 12345 JKLMNOPQRSTUVWXyz abcdefgh JKLMNOPQRSTUVWXyz", "zzzz abcdefghi JKLMNOPQRSTUVWXz", out);
        cout << n << " \"" << out << "\"\n"; }
    return 0;
}