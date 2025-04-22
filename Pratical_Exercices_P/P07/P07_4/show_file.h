#ifndef __show_file_h__
#define __show_file_h__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

//! Show file name and the contents.
void show_file(const std::string& file) {
  std::ifstream in(file);
  std::cout << "==> " << file << " <==\n";
  for (std::string line; getline(in, line); )
    std::cout << line << '\n';
}
#endif // __show_file_h__