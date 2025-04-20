#ifndef __cdata_h__
#define __cdata_h__

struct cdata {
  int count;
  int value;
};

int* expand_cdata(const cdata a[], int n);

#include <iostream>

void print_array(const int a[], int n){
  if (n == 0) {
    std::cout << "[]\n";
    return;
  }
  std::cout << '[' << a[0];
  for (int i = 1; i < n; i++) {
    std::cout << ',' << a[i];
  }
  std::cout << "]\n";
}
#endif // __cdata_h__