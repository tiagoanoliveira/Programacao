//
// Created by tiago-oliveira on 22-04-2025.
//

using namespace std;

class Fraction {
private:
    int numerator_;
    int denominator_;
    int gcd(int a, int b);
    void normalise();
public:
    Fraction() : numerator_(0), denominator_(1){}
    Fraction(int num, int den): numerator_(num), denominator_(den) {
        normalise();
    }
    Fraction sum(const Fraction& right);
    Fraction sub(const Fraction& right);
    Fraction mul(const Fraction& right);
    Fraction div(const Fraction& right);

    void write() const;
};

Fraction Fraction::sum(const Fraction& right) {
    int num = numerator_ * right.denominator_ + right.numerator_ * denominator_;
    int denom = denominator_ * right.denominator_;
    return Fraction(num, denom);
}

Fraction Fraction::sub(const Fraction& right) {
    int num = numerator_ * right.denominator_ - right.numerator_ * denominator_;
    int denom = denominator_ * right.denominator_;
    return Fraction(num, denom);
}

Fraction Fraction::mul(const Fraction& right) {
    int num = numerator_ * right.numerator_;
    int denom = denominator_ * right.denominator_;
    return Fraction(num, denom);
}

Fraction Fraction::div(const Fraction &right) {
    int num = numerator_ * right.denominator_;
    int denom = denominator_ * right.numerator_;
    return Fraction(num, denom);
}


#include "fraction_aux.h"

int main () {
    { Fraction().sum({2, 4}).write(); std::cout << ' ';
        Fraction(1,1).sum({2, 4}).write(); std::cout << ' ';
        Fraction(2,4).sum({3, 9}).write(); std::cout << ' ';
        Fraction(-2,4).sum({1, 2}).write(); std::cout << ' ';
        Fraction(3,27).sum({-27, 81}).write(); std::cout << '\n'; }
    { Fraction().sub({2, 4}).write(); std::cout << ' ';
        Fraction(1,1).sub({2, 4}).write(); std::cout << ' ';
        Fraction(2,4).sub({3, 9}).write(); std::cout << ' ';
        Fraction(-2,4).sub({1, 2}).write(); std::cout << ' ';
        Fraction(3,27).sub({-27, 81}).write(); std::cout << '\n'; }
    { Fraction().mul({2, 4}).write(); std::cout << ' ';
        Fraction(1,1).mul({2, 4}).write(); std::cout << ' ';
        Fraction(2,4).mul({3, 9}).write(); std::cout << ' ';
        Fraction(-2,4).mul({1, 2}).write(); std::cout << ' ';
        Fraction(3,27).mul({-27, 81}).write(); std::cout << '\n'; }
    { Fraction().div({2, 4}).write(); std::cout << ' ';
        Fraction(1,1).div({2, 4}).write(); std::cout << ' ';
        Fraction(2,4).div({3, 9}).write(); std::cout << ' ';
        Fraction(-2,4).div({1, 2}).write(); std::cout << ' ';
        Fraction(3,27).div({-27, 81}).write(); std::cout << '\n'; }
    return 0;
}