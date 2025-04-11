#ifndef __fraction_h__
#define __fraction_h__

//! Fraction
struct fraction {
  int num;  // Numerator
  int den;  // Denominator
};

//! Compute the gcd of two numbers.
int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

//! Normalize a fraction.
fraction normalize(fraction f) {
  int g = gcd(f.num, f.den);
  int num = f.num / g;
  int den = f.den / g;
  if (den < 0) {
    num = -num;
    den = -den;
  }
  return { num, den };
}

#include <iostream>
using std::ostream;

ostream& operator<<(ostream& out, fraction f) {
  if (f.den == 1) 
    out << f.num;
  else
    out << f.num << '/' << f.den;
  return out;
}

#endif // __fraction_h__
