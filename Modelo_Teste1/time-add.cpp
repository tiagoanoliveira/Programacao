//
// Created by tiago-oliveira on 17-03-2025.
//
#include <iostream>
using namespace std;
int main() {
    int h,m,delta;
    cin >> h >> m >> delta;
    int n=delta%60;
    h+=((delta-n)/60);
    m+=n;
    if (m>=60) {
        m-=60;
        h++;
    }
    if (h>=24) {
        h-=24;
    }
    cout << h << " " << m;
    return 0;
}
