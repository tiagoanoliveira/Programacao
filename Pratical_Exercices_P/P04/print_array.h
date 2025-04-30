#ifndef __print_array_h__
#define __print_array_h__

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

#endif // __print_array_h__
