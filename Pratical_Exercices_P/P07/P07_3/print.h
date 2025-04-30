
#ifndef __print_h__
#define __print_h__

#include <iostream>
#include <fstream>
#include <sstream>

//! Show file contents with line number information and 
//! the '|' character indicating the begin and end of lines.
void print(const std::string& file) {
  std::ifstream in(file);
  size_t line_nr = 1;
  for (std::string line; getline(in, line);) {
     std::cout << line_nr << "|" << line << "|\n";
     line_nr++;
  }
}
#endif // __print_h__