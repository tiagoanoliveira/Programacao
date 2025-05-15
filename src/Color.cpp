#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::Color() : r(0), g(0), b(0) {
    }

    Color::Color(const Color &other) : r(other.r), g(other.g), b(other.b) {
    }

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) : r(red), g(green), b(blue) {
    }

    rgb_value Color::red() const { return r; }
    rgb_value &Color::red() { return r; }

    rgb_value Color::green() const { return g; }
    rgb_value &Color::green() { return g; }

    rgb_value Color::blue() const { return b; }
    rgb_value &Color::blue() { return b; }

    // Implementação do operador ==
    bool Color::operator==(const Color &other) const {
        return r == other.r && g == other.g && b == other.b;
    }

    // Implementação do operador !=
    bool Color::operator!=(const Color &other) const {
        return !(*this == other);
    }
}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    return output;
}
