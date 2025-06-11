//
// Created by tiago-oliveira on 22-04-2025.
//
#include "Date2.h"
#include <sstream>
using namespace std;

Date::Date(): year(1), month(1), day(1) {
    //Se não tiver parâmetros a data é 0001/01/01
}

Date::Date(int y, int m, int d): year(0), month(0), day(0) {
    if (y >= 1 && y <= 9999 && m >= 1 && m <= 12 && d >= 1 && d <= num_days(y, m)) {
        year = y;
        month = m;
        day = d;
    }
}

Date::Date(const std::string &year_month_day): year(0), month(0), day(0) {
    int y, m, d;
    char separator1, separator2;
    istringstream datastring(year_month_day);
    if (datastring >> y >> separator1 >> m >> separator2 >> d) {
        if (separator1 == '/' && separator2 == '/') {
            *this = Date(y,m,d);
        }
    }
}

int Date::get_day() const {
    return day;
}

int Date::get_month() const {
    return month;
}

int Date::get_year() const {
    return year;
}

bool Date::is_valid() const {
    if (year == 0 || month == 0 || day == 0) {
        return false;
    }
    return true;
}

int Date::num_days(int year, int month) {
    int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return 29;
    return n_days[month - 1];
}

int main () {
    Date d1; d1.write(); std::cout << (d1.is_valid() ? "" : "-invalid") << endl;
    Date d2(2022, 4, 31); d2.write(); std::cout << (d2.is_valid() ? "" : "-invalid") << endl;
    Date d3("2ooo/2/28"); d3.write(); std::cout << (d3.is_valid() ? "" : "-invalid") << endl;
    Date d4("1900/1/1"); d4.write(); std::cout << (d4.is_valid() ? "" : "-invalid") << endl;
    Date d5("2022#12#31"); d5.write(); std::cout << (d5.is_valid() ? "" : "-invalid") << endl;
    return 0;
}