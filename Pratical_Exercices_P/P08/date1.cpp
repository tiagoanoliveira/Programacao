//
// Created by tiago-oliveira on 22-04-2025.
//
#include "Date1.h"
using namespace std;

Date::Date() {
    year=1;
    month=1;
    day=1;
}
Date::Date(int year, int month, int day) {
    this->year=year;
    this->month=month;
    this->day=day;
}

int Date::get_year() const {
    return year;
}

int Date::get_day() const {
    return day;
}

int Date::get_month() const {
    return month;
}



bool is_before(const Date& date1, const Date& date2) {
    if (date1.get_year()<date2.get_year()) return true;
    if (date1.get_year()>date2.get_year()) return false;
    if (date1.get_year()==date2.get_year()) {
        if (date1.get_month()<date2.get_month()) return true;
        if (date1.get_month()>date2.get_month()) return false;
        if (date1.get_month()==date2.get_month()) {
            if (date1.get_day()<date2.get_day()) return true;
        }
    }
    return false;
}

int main () {
    Date d1; d1.write(); std::cout << '\n';
    Date d2(2020, 2, 29); d2.write(); std::cout << '\n';
    Date d3(1925, 4, 30); d3.write(); std::cout << '\n';
    Date d4, d5(2022,4,29); d4.write(); std::cout << '-' << boolalpha << is_before(d4, d5) << '\n';
    Date d6(2023,10,31), d7(2022, 4, 29); d6.write(); std::cout << '-' << boolalpha << is_before(d6, d7) << '\n';
    return 0;
}