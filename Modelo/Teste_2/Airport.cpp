//
// Created by tiago-oliveira on 16-06-2025.
//
#include "Airport.h"
#include <iostream>
using namespace std;

Airport::Airport(const std::string &name, const std::string &city): name_(name), city_(city) {}

std::string Airport::city() const {
    return city_;
}

std::string Airport::name() const {
    return name_;
}
void Airport::land(const airplane &ap) {
    airplanes_.push_back(ap);
}
void Airport::takeoff(const std::string &id) {
    int counter=airplanes_.size();
    for (int i=0; i<counter; i++) {
        if (airplanes_[i].id==id) {
            airplanes_.erase(airplanes_.begin()+i);
            break;
        }
    }
}
int Airport::count_airplanes(const std::string &airline) const {
    int size=airplanes_.size();
    int counter=0;
    for (int i=0; i<size; i++) {
        if (airplanes_[i].airline==airline) counter++;
    }
    return counter;
}



int main() {
    {
        Airport a("Sa Carneiro", "Porto");
        std::cout << a.name() << '/' << a.city() << '/'
                  << a.count_airplanes("TAP") << ' '
                  << a.count_airplanes("British Arways") << ' '
                  << a.count_airplanes("Iberia") << '\n';
    }
    {
        Airport a("Sa Carneiro", "Porto");
        airplane aps[] = {{"TP000",  "TAP"},
                          {"TP123",  "TAP"},
                          {"RY456",  "Rynair"},
                          {"BA789",  "British Arways"},
                          {"TP1000", "TAP"}};
        for (airplane ap: aps) a.land(ap);
        std::cout << a.name() << '/' << a.city() << '/'
                  << a.count_airplanes("TAP") << ' '
                  << a.count_airplanes("British Arways") << ' '
                  << a.count_airplanes("Rynair") << '\n';
    }
    return 0;
}