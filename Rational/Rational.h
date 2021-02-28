#pragma once
#include <iostream>

/**
 * �����, x/y
 */
class Rational {
    friend std::ostream& operator<< (std::ostream& out, const Rational& rational);
    friend std::istream& operator>> (std::istream& in, Rational& rational);

public:
    // not a number
    // ���������, ��� ����� �� �������� ������
    // �� �������� � float
    // ��������������� � true,
    // ���� ��������� ��������
    // � �������� �� ����
    bool nan;
    int numerator;
    int denumerator;

    Rational();
    Rational(int, int);
    Rational(int);

    // ����������
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

    // ������� �� �����
    void print();
    // ������� � ����������
    void scan();

    //���������� ����������
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
