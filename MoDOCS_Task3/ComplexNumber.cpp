/*
 * This file is part of MoDOCS_Task3 which is released under MIT License.
 * Created by triod315 on 10/31/21, 12:44 PM
 * Copyright (c) 2021.
 */
#include "ComplexNumber.h"
#include "math.h"

ComplexNumber::ComplexNumber (double re, double im) {
    RealPart=re;
    ImaginaryPart=im;
}

double ComplexNumber::Modulus() {
    return sqrt(RealPart*RealPart+ImaginaryPart*ImaginaryPart);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &complexNumber) const{
    ComplexNumber newNumber;
    newNumber.RealPart=RealPart+complexNumber.RealPart;
    newNumber.ImaginaryPart=ImaginaryPart+complexNumber.ImaginaryPart;
    return newNumber;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &complexNumber) const {
    ComplexNumber newNumber;
    newNumber.RealPart=RealPart-complexNumber.RealPart;
    newNumber.ImaginaryPart=ImaginaryPart-complexNumber.ImaginaryPart;
    return newNumber;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &complexNumber) const {
    ComplexNumber newNumber;
    newNumber.RealPart=RealPart*complexNumber.RealPart-ImaginaryPart*complexNumber.ImaginaryPart;
    newNumber.ImaginaryPart=RealPart*complexNumber.ImaginaryPart+ImaginaryPart*complexNumber.RealPart;
    return newNumber;
}

ComplexNumber::ComplexNumber() {
    ImaginaryPart=RealPart=0;
}

std::string ComplexNumber::toString() {
    return std::to_string(RealPart)+" + "+ std::to_string(ImaginaryPart)+"i";
}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &complexNumber) {
    *this= *this+complexNumber;
    return *this;
}

ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &complexNumber) {
    *this= *this*complexNumber;
    return *this;
}




