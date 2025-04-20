//
// Created by tiago-oliveira on 17-03-2025.
//
#include <iostream>
using namespace std;
int score(char word[], int n) {
    int points[26]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int total=0;
    for (int i=0; i<n; i++) {
        char c=word[i];
        if (c>='a' && c<='z') total+=points[c-'a'];
    }
    return total;
}
int main () {
    { char word[] = "hello";
        std::cout << score(word, 5) << std::endl; }
    { char word[] = "world";
        std::cout << score(word, 5) << std::endl; }
    { char word[] = "hello, world";
        std::cout << score(word, 12) << std::endl; }
    { char word[] = "abcdefghijklmnopqrstuvwxyz";
        std::cout << score(word, 26) << std::endl; }
    return 0;
}