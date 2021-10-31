/*
 * This file is part of MoDOCS_Task3 which is released under MIT License.
 * Created by triod315 on 10/31/21, 12:44 PM
 * Copyright (c) 2021.
 */

#ifndef AOCS_TASK3_COMPLEXARRAY_H
#define AOCS_TASK3_COMPLEXARRAY_H
#include <vector>
#include <string.h>
#include "ComplexNumber.h"


class ComplexArray {
private:
    ComplexNumber* _internalArray;
    size_t _size;
public:
    ComplexArray(size_t size);
    void printAllItems();
    void printItemAt(int index);
    size_t GetLenth();
    void AddToEnd(ComplexNumber number);
    void AddToEnd(double re, double im);
    ComplexNumber MaxByModulus();
    ComplexNumber SumAll();
    ComplexNumber ProductionAll();
    double ModulusSumAll();
    ComplexNumber& operator[](int index);

    ~ComplexArray();
};


#endif //AOCS_TASK3_COMPLEXARRAY_H
