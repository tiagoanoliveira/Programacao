//
// Created by tiago-oliveira on 23-02-2025.
//
#include <iostream>
using namespace std;
int main(){
    int a, sum=0;
    cin >> a;
    int x1, y1;
    cin >> x1 >> y1;
    for (int i=1; i<a; i++){
        int x2, y2;
        cin >> x2 >> y2;
        sum+=abs(x1-x2);
        sum+=abs(y1-y2);
        x1=x2;
        y1=y2;
    }
    cout << sum;
    return 0;
}