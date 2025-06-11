//
// Created by tiago-oliveira on 22-04-2025.
//
#include "Date3.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

Date::Date(): yyyymmdd("00010101") {
    //Se não tiver parâmetros a data é 0001/01/01
}

Date::Date(int y, int m, int d): yyyymmdd("00000000") {
    if (y >= 1 && y <= 9999 && m >= 1 && m <= 12 && d >= 1 && d <= num_days(y, m)) {
        int year = y;
        int month = m;
        int day = d;
        int datastrin=year*10000+month*100+day;
        string datas =to_string(datastrin);
        yyyymmdd= datas;
    }


}

Date::Date(const std::string &year_month_day): yyyymmdd("00000000") {
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
    return stoi(yyyymmdd.substr(6, 2));
}

int Date::get_month() const {
    return stoi(yyyymmdd.substr(4, 2));
}

int Date::get_year() const {
    return stoi(yyyymmdd.substr(0, 4));
}

bool Date::is_valid() const {
    int year = get_year();
    int month = get_month();
    int day = get_day();
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