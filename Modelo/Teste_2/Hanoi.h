#ifndef __HANOI_H__
#define __HANOI_H__

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <initializer_list>

using std::string;
using std::vector;
using std::ostringstream;

class Tower {
public:
    Tower(int n_disks); // build empty tower with capacity for n_disks
    ~Tower();           // Destructor
    int top() const;    // disk at the top (0 if none)
    void add(int disk); // add disk to the top
    void remove();      // remove disk from the top (no effect if empty)
    string str() const; // obtain string representation of tower (see public tests)
private:
    int n_disks; // Maximum capacity of tower
    int *disks_; // Dynamically allocated array, cannot use vector
    int idx_top; // Index of the disk currently on top (-1 if none)
};

struct disk_move {
  int from, to;        // tower numbers (0, 1, 2)
};

class Hanoi {
public:
  Hanoi(int n_disks) : towers_{Tower(n_disks), Tower(n_disks), Tower(n_disks)} {
    for (int i = n_disks; i > 0; i--) {
        // First tower contains all three disks: 3-2-1
        towers_[0].add(i);
    }
  }

  void move(std::initializer_list<disk_move> dmoves);

  string str() const {
    ostringstream oss;
    oss << towers_[0].str() << towers_[1].str() << towers_[2].str();
    return oss.str();
  }
private:
  Tower towers_[3];
};

#endif