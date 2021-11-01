/*
 * This file is part of MoDOCS_Task3 which is released under MIT License.
 * Created by triod315 on 10/31/21, 12:44 PM
 * Copyright (c) 2021.
 */

#include "ComplexArray.h"
#include "iostream"
ComplexArray::ComplexArray(size_t size) {
    _internalArray = new ComplexNumber[size];
    _size=size;
}
ComplexArray::~ComplexArray() {
    delete [] _internalArray;
}
void ComplexArray::AddToEnd(ComplexNumber number) {
    /* для додавання в кінець масиву створюється новий масив, розмір якого
     * на 1 ьільший від існуючого і в нього копіюється вміст існуючого масиву,
     * в кінець записується новий елемент, а старий масив видаляється.
     */
    size_t newSize=_size+1;
    ComplexNumber * newArr = new ComplexNumber[newSize];
    memcpy(newArr, _internalArray, _size * sizeof(ComplexNumber));
    _size=newSize;
    delete [] _internalArray;
    _internalArray=newArr;
    _internalArray[_size-1]=number;
}
void ComplexArray::printAllItems() {
    std::cout<<"All items in array"<<std::endl;
    for (size_t i = 0; i < _size; i++) {
        std::cout<<_internalArray[i].toString()<<std::endl;
    }
}
void ComplexArray::AddToEnd(double re, double im) {
    ComplexNumber complexNumber(re,im);
    AddToEnd(complexNumber);
}
void ComplexArray::printItemAt(int index) {
    std::cout<<"Element at index "<<std::to_string(index)<<std::endl;
    std::cout<<_internalArray[index].toString()<<std::endl;
}
size_t ComplexArray::GetLenth() {
    return _size;
}
ComplexNumber ComplexArray::MaxByModulus() {
    ComplexNumber max=_internalArray[0];
    for (size_t i = 1; i < _size; i++) {
        if (_internalArray[i].Modulus()>max.Modulus())
            max=_internalArray[i];
    }
    return max;
}
ComplexNumber ComplexArray::SumAll() {
    ComplexNumber result;
    for (int i = 0; i < _size; i++) {
        result+=_internalArray[i];
    }
    return result;
}
double ComplexArray::ModulusSumAll() {
    double result = _internalArray[0].Modulus();
    for (size_t i = 1; i < _size; i++) {
        result+=_internalArray[i].Modulus();
    }
    return result;
}
ComplexNumber ComplexArray::ProductionAll() {
    ComplexNumber result=_internalArray[0];
    for (int i = 1; i < _size; i++) {
        result*=_internalArray[i];
    }
    return result;
}
ComplexNumber &ComplexArray::operator[](int index) {
    if (index>=_size)
        throw std::out_of_range ("Index out of rage");
    return _internalArray[index];
}
