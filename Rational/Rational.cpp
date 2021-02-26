#include "Rational.h"
#include <iostream>


int gcd(int a, int b) {
    if (b == 0) { return a; }
    else { a = int(gcd(b, a % b)); }
    return a;
}

Rational::Rational() {
    numerator = 1;
    denumerator = 1;
    nan = false;
}

Rational::Rational(int x, int y) {
    numerator = x;
    denumerator = y;

    // Если y равен 0
    // значит выполнили где-то
    // деление на 0
    // выставим nan в true
    nan = (y == 0);
}

Rational::Rational(int x) {
    numerator = x;
    denumerator = 1;
    nan = false;
}

Rational Rational::reduce() {
    int nod = gcd(this->numerator, this->denumerator);
    return Rational(this->numerator / nod, this->denumerator / nod);
}

void Rational::print() {
    if (nan)
        std::cout << "<NAN>\n";
    else
        std::cout
        << numerator
        << "/"
        << denumerator
        << std::endl;
}

Rational Rational::neg() {
    return Rational(
        -1 * numerator,
        denumerator
    );
}

Rational Rational::inv() {
    return Rational(
        denumerator,
        numerator
    );
}

bool Rational::eq(Rational r) {
    return
        numerator == r.numerator
        &&
        denumerator == r.denumerator;
}

bool Rational::neq(Rational r) {
    return !eq(r);
}

Rational Rational::sum(Rational r) {
    return Rational(
        this->numerator * r.denumerator + this->denumerator * r.numerator,
        this->denumerator * r.denumerator
    );
}

Rational Rational::sub(Rational r) {
    return Rational(
        this->numerator * r.denumerator - this->denumerator * r.numerator,
        this->denumerator * r.denumerator
    );
}

Rational Rational::mul(Rational r) {
    return Rational(
        numerator * r.numerator,
        denumerator * r.denumerator
    );
}

Rational Rational::div(Rational r) {
    r = r.inv();
    return Rational(this->numerator * r.numerator,
        this->denumerator * r.denumerator
    );
}

// inv
// sum/sub/mul/div
//через перегрузку
Rational Rational::operator+ (Rational r) {
    return sum(r);
}

Rational Rational::operator- (Rational r) {
    return sub(r);
}

Rational Rational::operator* (Rational r) {
    return mul(r);
}

Rational Rational::operator/ (Rational r) {
    return div(r);
}