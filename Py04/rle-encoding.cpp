//
// Created by tiago-oliveira on 18-03-2025.
//
#include <iostream>
using namespace std;
int int_to_str(int n, char str[]) {
    int qt=0;
    int temp=n;
    if (temp<10) {
        str[0]=temp+'0';
        return 1;
    }
    while (temp!=0) {
        int res=temp%10;
        str[qt]=res+'0';
        qt++;
        temp-=res;
        temp/=10;
    }
    for (int i=0; i<(qt/2); i++) {
        const char first=str[i];
        str[i]=str[qt-i-1];
        str[qt-i-1]=first;
    }
    str[qt]='\0';
    return qt;
}
void rle_organize(const int n, const char last, int& pos, char rle[]) {
    char str[10];
    const int qt=int_to_str(n, str);
    for (int i=0; i<qt; i++) {
        rle[pos++]=str[i];
    }
    rle[pos++]=last;
}
void rle_encode(const char str[], char rle[]) {
    int current=0;
    int pos=0;
    while (str[current]!='\0') {
        const char last=str[current];
        int count=0;
        while (str[current]==last) {
            count++;
            current++;
        }
        rle_organize(count, last, pos, rle);
    }
    rle[pos]='\0';
}
int main() {
    { char rle[1] = { -1 };
        rle_encode("", rle);
        std::cout << rle << '\n'; }
    { char rle[2 + 1] = { -1, -1, -1 };
        rle_encode("a", rle);
        std::cout << rle << '\n'; }
    { char rle[10 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        rle_encode("abcde", rle);
        std::cout << rle << '\n'; }
    { char rle[9 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
        rle_encode("aaaaabbbbbbbbbbbcccd", rle);
        std::cout << rle << '\n'; }
    { char rle[3 + 1] = { -1, -1, -1, -1 };
        rle_encode("xxxxxxxxxxxxxxxxxxxx", rle);
        std::cout << rle << '\n'; }
    return 0;
}
