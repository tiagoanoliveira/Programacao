//
// Created by tiago-oliveira on 16-03-2025.
//
#include "vect3d.h"
#include <iostream>
using namespace std;
vect3d cross (vect3d a, vect3d b) {
    vect3d u;
    u.x=a.y*b.z-a.z*b.y;
    u.y=a.z*b.x-a.x*b.z;
    u.z=a.x*b.y-a.y*b.x;
    return u;
}
int main () {
    { vect3d a({1, 2, 3}); vect3d b({3 ,4, 5});
        std::cout << cross(a, b) << '\n'; }
    { vect3d a({0, 0, 0}); vect3d b({0, 0, 0});
        std::cout << cross(a, b) << '\n'; }
    { vect3d a({5, 1, 3}); vect3d b({5, 1, 3});
        std::cout << cross(a, b) << '\n'; }
    return 0;
}