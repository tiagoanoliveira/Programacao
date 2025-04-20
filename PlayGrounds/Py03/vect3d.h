#ifndef __vect3d_h__
#define __vect3d_h__

struct vect3d {
    float x;
    float y;
    float z;
};

#include <iostream>
using std::ostream;

ostream& operator<<(ostream& out, vect3d t) {
    out << "(" << t.x << ", " << t.y << ", " << t.z << ")";
    return out;
}

#endif // __vect3d_h__
