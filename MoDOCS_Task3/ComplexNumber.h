/*
 * This file is part of MoDOCS_Task3 which is released under MIT License.
 * Created by triod315 on 10/31/21, 12:44 PM
 * Copyright (c) 2021.
 */

//
// Created by triod315 on 10/30/2021.
//

#ifndef AOCS_TASK3_COMPLEXNUMBER_H
#define AOCS_TASK3_COMPLEXNUMBER_H
#include <string>

class ComplexNumber {
public:
    double RealPart;
    double ImaginaryPart;

    ComplexNumber();

    ComplexNumber(double re, double im);

    double Modulus();

    ComplexNumber operator+(const ComplexNumber & complexNumber) const;
    ComplexNumber operator-(const ComplexNumber & complexNumber) const;
    ComplexNumber operator*(const ComplexNumber & complexNumber) const;
    ComplexNumber& operator+=(const ComplexNumber& complexNumber);
    ComplexNumber& operator*=(const ComplexNumber& complexNumber);

    std::string toString();
};


#endif //AOCS_TASK3_COMPLEXNUMBER_H
