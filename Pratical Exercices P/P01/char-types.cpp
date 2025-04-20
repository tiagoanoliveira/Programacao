//
// Created by tiago-oliveira on 16-02-2025.
//
#include <iostream>
using namespace std;
int main() {
    int n;
    int ch=0;
    int val=0;
    int sym=0;
    cin >> n;
    for (int i=0; i < n; i++) {
        char c;
        cin >> c;
        if (('A'<= c && c <='Z') or ('a' <= c && c <= 'z')) {
            ch++;
        }
        else if ('0' <= c && c <= '9') {
            val++;
        }
        else {
            sym++;
        }

    }
    cout << ch << ' ' << val << ' ' << sym <<endl;
    return 0;
}
