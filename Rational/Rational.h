#pragma once
#include <iostream>

/**
 * Дробь, x/y
 */
class Rational {
    friend std::ostream& operator<< (std::ostream& out, const Rational& rational);
    friend std::istream& operator>> (std::istream& in, Rational& rational);

public:
    // not a number
    // Указывает, что число не является числом
    // по аналогии с float
    // Устанавливается в true,
    // если выполнили операцию
    // с делением на ноль
    bool nan;
    int numerator;
    int denumerator;

    Rational();
    Rational(int, int);
    Rational(int);

    // Сокращение
    Rational reduce();

    // *-1
    Rational neg();
    // ^-1
    Rational inv();

    Rational sum(Rational);
    Rational sub(Rational);
    Rational mul(Rational);
    Rational div(Rational);

    // ==
    bool eq(Rational);
    // !=
    bool neq(Rational);
    // less than
    // <
    bool l(Rational);
    // less or equal than
    // <=
    bool leq(Rational);
    // greater than
    // >
    bool g(Rational);
    // greater or equal than
    // >=
    bool geq(Rational);

    // Вывести на экран
    void print();
    // Считать с клавиатуры
    void scan();

    //Перегрузка операторов
    Rational operator+ (Rational);
    Rational operator- (Rational);
    Rational operator* (Rational);
    Rational operator/ (Rational);

    bool operator< (Rational);
    bool operator<= (Rational);
    bool operator> (Rational);
    bool operator>= (Rational);
    bool operator== (Rational);
    bool operator!= (Rational);

    bool checkNanOperation();
};
