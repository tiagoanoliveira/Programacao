//
// Created by tiago-oliveira on 22-04-2025.
//

#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    Color(unsigned char red, unsigned char green, unsigned char blue);
    Color(const Color& c);
    unsigned char red() const;
    unsigned char green() const;
    unsigned char blue() const;
    bool equal_to(const Color& other) const;
    void invert();
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color BLACK;
    static const Color WHITE;
private:
    unsigned char red_code, blue_code, green_code;
};
#endif //COLOR_H
