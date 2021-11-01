/*
 * This file is part of MoDOCS_Task3 which is released under MIT License.
 * Created by triod315 on 10/31/21, 12:44 PM
 * Copyright (c) 2021.
 */
#ifndef AOCS_TASK3_COMPLEXNUMBER_H
#define AOCS_TASK3_COMPLEXNUMBER_H
#include <string>
/*
 * Клас для представлення комплексного числа.
 * Перевантажує оператори додавання, віднімання, множення та присвоєння з
 * з додаванням та множенням.
 */
class ComplexNumber {
public:
    /// Дійсна частина комплексного числа.
    double RealPart;
    /// Уявна частина комплексного числа.
    double ImaginaryPart;

    /// Конструктор комплексного числа без параметрів.
    ComplexNumber();

    /// Конструктор комплексног числа з двома параметрами.
    /// \param re дійсна частина комплексного числа.
    /// \param im уявна частина комплексного числа.
    ComplexNumber(double re, double im);

    /// Функція для одеражння модуля комплексного числа.
    /// \return модуль комплексного числа.
    double Modulus();

    /// Перевантаження оператора додавання.
    ComplexNumber operator+(const ComplexNumber & complexNumber) const;
    /// Перевантаження оператора віднімання.
    ComplexNumber operator-(const ComplexNumber & complexNumber) const;
    /// Перевантаження оператора множення.
    ComplexNumber operator*(const ComplexNumber & complexNumber) const;
    /// Перевантаження оператора присвоєння з додаванням.
    ComplexNumber& operator+=(const ComplexNumber& complexNumber);
    /// Перевантаження оператора присвоєння з множенням.
    ComplexNumber& operator*=(const ComplexNumber& complexNumber);
    /// Функція для перетворення комплексного числа в рядок.
    std::string toString();
};
#endif //AOCS_TASK3_COMPLEXNUMBER_H
