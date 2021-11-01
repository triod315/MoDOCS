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
/*
 * Клас для описання масиву комплекних чисел, дозволяє виконати наступні операції:
 *  a.	Відображення всіх чисел на екрані
 *  b.	Відображення n-ого числа
 *  c.	Одержання n-ого числа, додавання числа в кінець масиву
 *  d.	Знаходження найбільшого за модулем числа
 *  e.	Знаходження суми всіх чисел
 *  f.	Знаходження суми модулів всіх чисел, знаходження добутку всіх чисел
 */
class ComplexArray {
private:
    /// вказівник на внутрішній масив комплексних чисел.
    ComplexNumber* _internalArray;
    /// кількість елементів масиву.
    size_t _size;
public:
    /// Конструктор масиву, який створює масив розміром size.
    /// \param size кількість елементів масиву.
    ComplexArray(size_t size);
    /// Вивід всіх елеменів масиву на консоль.
    void printAllItems();
    /// Вивід елементу що знаходиться за вказаним індексом.
    /// \param index ідекс елементу в масиві.
    void printItemAt(int index);
    /// Функція, яка повертає кількість елементів масиву.
    size_t GetLenth();
    /// Додавання нового елементу в кінець масиву.
    /// \param number комплексне число, яке буде додано в кінець масиу.
    void AddToEnd(ComplexNumber number);
    /// Додавання нового елементу в кінець масиву.
    /// \param re дійсна частина новго комплексного числа.
    /// \param im уявна частина новго комплекного числа.
    void AddToEnd(double re, double im);
    /// Функція для одержання максимального за модулем числа.
    /// \return комплексне число з максимальним значенням його модуля.
    ComplexNumber MaxByModulus();
    /// Функція яка повертає суму всіх комплексних чисел.
    /// \return сума всіх комплексних чисел масиву.
    ComplexNumber SumAll();
    /// Функція яка повертає добуток всіх комплекних чисел.
    /// \return добуток всіх комплексних чисел масиву.
    ComplexNumber ProductionAll();
    /// Функція для одержання суми модулів всіх комплексних чисел.
    /// \return сума модулів всіх комплексних чисел.
    double ModulusSumAll();
    /// Перевизначення оператора [] для звернення до елементів масиву по індексу.
    /// \param index індекс шуканого елементу.
    /// \return елемент за вказаним індексом.
    ComplexNumber& operator[](int index);
    /// Деструктор для звільнення пам'яті.
    ~ComplexArray();
};
#endif //AOCS_TASK3_COMPLEXARRAY_H
