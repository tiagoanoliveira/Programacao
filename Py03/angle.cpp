//
// Created by tiago-oliveira on 17-03-2025.
//
#include <cmath>

#include "vect3d.h"
#include <iostream>
using namespace std;
float norm(const vect3d c) {
    float m=sqrt(c.x*c.x+c.y*c.y+c.z*c.z);
    return m;
}
int angle(vect3d a, vect3d b) {
    float n=(a.x*b.x+a.y*b.y+a.z*b.z)/(norm(a)*norm(b));
    float rad=acos(n);
    int ang=round(rad*180/3.1415);
    return ang;
}
int main () {
    { vect3d a({1, 0, 0}); vect3d b({0, 1, 0});
        std::cout << angle(a, b) << '\n'; }
    { vect3d a({1, 0, 0}); vect3d b({2, 0, 0});
        std::cout << angle(a, b) << '\n'; }
    { vect3d a({2, 3, 4}); vect3d b({1, 5, 6});
        std::cout << angle(a, b) << '\n'; }
    { vect3d a({1, 0, 0}); vect3d b({-1, 0, 0});
        std::cout << angle(a, b) << '\n'; }
    return 0;
}