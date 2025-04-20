#ifndef __complex_h__
#define __complex_h__

// Representation of a complex number z = x + y i
struct complex {
  double real; // Real part
  double img;  // Imaginary part
};

double norm(const complex& c);
void add(const complex& a, const complex& b, complex& r);
void mul(const complex& a, const complex& b, complex& r);

#include <iostream>
#include <iomanip>
using std::ostream;

ostream& operator<<(ostream& out, const complex& c) {
  return out << std::fixed << std::setprecision(3)
             << c.real
             << (c.img >= 0.0 ? "+" : "")
             << c.img << "i";
}

#endif // __complex_h__
