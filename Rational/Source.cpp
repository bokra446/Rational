#include "Rational.h"
#include <iostream>

int main() {
    Rational x; // 1/1
    Rational y(10, 5); // 10/5
    Rational z(7);

    std::cout << "x < y: ";
    std::cout << (x < y) << std::endl;
    std::cout << "x <= y: ";
    std::cout << (x <= y) << std::endl;
    std::cout << "x > y: ";
    std::cout << (x > y) << std::endl;
    std::cout << "x >= y: ";
    std::cout << (x >= y) << std::endl;
    std::cout << "x == y: ";
    std::cout << (x == y) << std::endl;
    std::cout << "x != y: ";
    std::cout << (x != y) << std::endl;
    std::cout << "z.neg(): ";
    z.neg().print();

    Rational n(10, 0);
    n.mul(Rational(1)).print();
    Rational(1).mul(n).print();
    std::cout << "x + y: ";
    (x + y).print();
    std::cout << "x - y: ";
    (x - y).print();
    std::cout << "x * y: ";
    (x * y).print();
    std::cout << "x / y: ";
    (x / y).print();
    y.reduce().print();
    Rational k;
    std::cout << "Enter fraction number" << std::endl;
    std::cin >> k;
    std::cout << k << std::endl;
}
