#ifndef __amount_h__
#define __amount_h__

struct amount {
    int euros;
    int cents;
};

#include <iostream>
using std::ostream;

ostream& operator<<(ostream& out, amount a) {
    out << a.euros << " euros and " << a.cents << " cents";
    return out;
}

#endif // __amount_h__
