#include "Rational.h"
#include <iostream>


int gcd(int a, int b) {
    if (b == 0) { return a; }
    else { a = int(gcd(b, a % b)); }
    return a;
}

bool Rational::checkNanOperation() {
    if (this->nan == 1) {
        std::cout << "NAN operation" << std::endl;
        return 1;
    }
    return 0;
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
    if (checkNanOperation()) {
        return *this;
    }
    int nod = gcd(this->numerator, this->denumerator);
    this->numerator = this->numerator / nod;
    this->denumerator = this->denumerator / nod;
    return *this;
    //return Rational(this->numerator / nod, this->denumerator / nod);
}

Rational Rational::neg() {
    return Rational(
        -1 * numerator,
        denumerator
    );
}

Rational Rational::inv() {
    if (checkNanOperation()) {
        return *this;
    }
    return Rational(
        denumerator,
        numerator
    );
}


Rational Rational::sum(Rational r) {
    if (checkNanOperation() || r.checkNanOperation()) {
        return Rational(0, 0);
    }
    return Rational(
        this->numerator * r.denumerator + this->denumerator * r.numerator,
        this->denumerator * r.denumerator
    );
}

Rational Rational::sub(Rational r) {
    if (checkNanOperation() || r.checkNanOperation()) {
        return Rational(0, 0);
    }
    return Rational(
        this->numerator * r.denumerator - this->denumerator * r.numerator,
        this->denumerator * r.denumerator
    );
}

Rational Rational::mul(Rational r) {
    if (checkNanOperation() || r.checkNanOperation()) {
        return Rational(0, 0);
    }
    return Rational(
        numerator * r.numerator,
        denumerator * r.denumerator
    );
}

Rational Rational::div(Rational r) {
    if (checkNanOperation() || r.checkNanOperation()) {
        return Rational(0, 0);
    }
    r = r.inv();
    return Rational(this->numerator * r.numerator,
        this->denumerator * r.denumerator
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

bool Rational::l(Rational r) {
    if (checkNanOperation() || r.checkNanOperation()) {
        return false;
    }
    if (this->numerator * r.denumerator < r.numerator * this->denumerator) {
        return true;
    }
    return false;
}

bool Rational::leq(Rational r) {
    if (checkNanOperation() || r.checkNanOperation()) {
        return false;
    }
    if (this->numerator * r.denumerator <= r.numerator * this->denumerator) {
        return true;
    }
    return false;
}

bool Rational::g(Rational r) {
    return !leq(r);
}

bool Rational::geq(Rational r) {
    return !l(r);
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

void Rational::scan() {
    std::cout << "Enter numerator" << std::endl;
    std::cin >> this->numerator;
    std::cout << "Enter denumerator" << std::endl;
    std::cin >> this->denumerator;
    if (!denumerator) {
        nan = true;
    }
}
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

bool Rational::operator< (Rational r) {
    return l(r);
}

bool Rational::operator<= (Rational r) {
    return leq(r);
}

bool Rational::operator> (Rational r) {
    return g(r);
}

bool Rational::operator>= (Rational r) {
    return geq(r);
}

bool Rational::operator== (Rational r) {
    return eq(r);
}

bool Rational::operator!= (Rational r) {
    return neq(r);
}

std::ostream& operator<< (std::ostream& out, const Rational& rational)
{
    if (rational.nan) {
        out << "NAN";
    }
    else {
        out << rational.numerator << " / " << rational.denumerator;
    }
    return out;
}

std::istream& operator>> (std::istream& in, Rational& rational)
{
    char line;
    //line принимает в себя разделительную черту - "/"
    in >> rational.numerator >> line >> rational.denumerator;
    if (rational.denumerator == 0) {
        rational.nan = true;
    }
    return in;
}