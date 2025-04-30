//
// Created by tiago-oliveira on 09-03-2025.
//
#include <iostream>
#include "interval.h"
void order_interval(interval& a, interval& b) {
  if (a.start.h>b.start.h or (a.start.h==b.start.h and a.start.m>b.start.m)) {
    const interval temp=a;
    a=b;
    b=temp;
  }
}

interval intersection(interval a, interval b) {
  order_interval(a,b);
  interval c = {};
  if (a.end.h > b.start.h || (a.end.h == b.start.h && a.end.m > b.start.m)) {
    c.start = (a.start.h > b.start.h || (a.start.h == b.start.h && a.start.m > b.start.m))? a.start: b.start;
    c.end = (a.end.h < b.end.h || (a.end.h == b.end.h && a.end.m < b.end.m)) ? a.end : b.end;
  }
  return c;
}

int main () {
  std::cout << intersection( { { 12, 30 }, { 14, 30 } },{ { 17, 30 }, { 18, 30 } } ) << '\n';
  std::cout << intersection( { { 12, 30 }, { 14, 30 } },{ { 14, 30 }, { 18, 30 } } ) << '\n';
  std::cout << intersection( { { 12, 30 }, { 14, 31 } },{ { 14, 30 }, { 18, 30 } } ) << '\n';
  std::cout << intersection( { { 14, 30 }, { 15, 59 } },{ { 11, 30 }, { 14, 31 } } ) << '\n';
  std::cout << intersection( { {  4, 30 }, {  7, 59 } },{ {  4,  0 }, {  7, 29 } } ) << '\n';
  std::cout << intersection( { { 23,  0 }, { 23, 58 } },{ { 22, 45 }, { 23, 59 } } ) << '\n';
  std::cout << intersection( { { 17,  0 }, { 19,  0 } }, { { 15,  0 }, { 17,  0 } } ) << '\n';
  return 0;
}
