//
// Created by tiago-oliveira on 23-02-2025.
//
#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i=0; i<n; i++) {
        cin >> sequence[i];
    }
    int maxsum=2;
    int current=2;
    int diff=sequence[1]-sequence[0];
    for (int i=2; i<n; i++) {
        int currentdiff=sequence[i]-sequence[i-1];
        if (currentdiff==diff) {
            current++;
        }
        else {
            current=2;
            diff=currentdiff;
        }
        maxsum=max(maxsum, current);
    }
    cout << maxsum;
    return 0;
}