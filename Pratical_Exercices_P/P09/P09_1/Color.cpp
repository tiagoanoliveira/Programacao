//
// Created by tiago-oliveira on 22-04-2025.
//
#include "Color.h"
#include <iostream>
using namespace std;

Color::Color(unsigned char red, unsigned char green, unsigned char blue): red_code(red), blue_code(blue), green_code(green) {}

Color::Color(const Color &c): red_code(c.red_code), blue_code(c.blue_code), green_code(c.green_code) {}

unsigned char Color::blue() const {
    return blue_code;
}

unsigned char Color::green() const {
    return green_code;
}

unsigned char Color::red() const {
    return red_code;
}

bool Color::equal_to(const Color &other) const {
    if (red_code==other.red_code && green_code==other.green_code && blue_code==other.blue_code) return true;
    return false;
}

void Color::invert() {
    red_code = 255- red_code;

    green_code = 255 - green_code;
    blue_code = 255 - blue_code;
}


const Color Color::RED   = Color(255, 0, 0);
const Color Color::GREEN = Color(0, 255, 0);
const Color Color::BLUE  = Color(0, 0, 255);
const Color Color::BLACK = Color(0, 0, 0);
const Color Color::WHITE = Color(255, 255, 255);

int main () {
    { Color c (1, 2, 3);
        const Color& r = c;
        std::cout << (int) r.red() << ' '
             << (int) r.green() << ' '
             << (int) r.blue() << ' '
             << std::boolalpha << r.equal_to(r) << '\n'; }
    { std::cout << boolalpha
       << Color::WHITE.equal_to(Color::WHITE) << ' '
       << Color::BLACK.equal_to(Color::RED) << ' '
       << Color::BLUE.equal_to(Color::GREEN) << '\n'; }
    { Color c(Color::WHITE);
        std::cout << (int) c.red() << ' '
             << (int) c.green() << ' '
             << (int) c.blue() << ' '
             << std::boolalpha << c.equal_to(Color::WHITE) << ' '
             << c.equal_to(Color::BLACK) << '\n'; }
    { Color c(Color::WHITE);
        c.invert();
        std::cout << (int) c.red() << ' '
             << (int) c.green() << ' '
             << (int) c.blue() << ' '
             << std::boolalpha << c.equal_to(Color::WHITE) << ' '
             << c.equal_to(Color::BLACK) << '\n'; }
    { Color c(255, 128, 12);
        c.invert();
        Color c2(c);
        c2.invert();
        std::cout << (int) c.red() << ' '
             << (int) c.green() << ' '
             << (int) c.blue() << ' '
             << std::boolalpha << c.equal_to({ 0, 127, 243 }) << ' '
             << (int) c2.red() << ' '
             << (int) c2.green() << ' '
             << (int) c2.blue() << ' '
             << std::boolalpha << c2.equal_to({ 255, 128, 12 }) << '\n'; }
    return 0;
}