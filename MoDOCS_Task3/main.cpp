/*
 * This file is part of MoDOCS_Task3 which is released under MIT License.
 * Created by triod315 on 10/31/21, 12:44 PM
 * Copyright (c) 2021.
 */
/*
 * Дана програма демонструє можливості класу ComplexArray, а саме:
 *  a.	Відображення всіх чисел на екрані
 *  b.	Відображення n-ого числа
 *  c.	Одержання n-ого числа, додавання числа в кінець масиву
 *  d.	Знаходження найбільшого за модулем числа
 *  e.	Знаходження суми всіх чисел
 *  f.	Знаходження суми модулів всіх чисел, знаходження добутку всіх чисел
 */
#include <iostream>
#include "ComplexArray.h"
// Макрос для виведення на консоль.
#define STD_PRINT(text, value) std::cout<<text<<value<<std::endl;

int main() {
    // створення масиву комплексних чисел.
    ComplexArray* complexArray = new ComplexArray(0);
    // додавання новго елементу в кінець масиву.
    complexArray->AddToEnd(1,1);
    complexArray->AddToEnd(2,3);
    complexArray->AddToEnd(5,8);
    // виведення довжини масиву.
    STD_PRINT("Array with length: ", complexArray->GetLenth())
    // виведення всіх елементів масиву.
    complexArray->printAllItems();
    // виведення елементу масиву за вказаним індексом.
    complexArray->printItemAt(2);
    // виведення елементу за вказаним індексом через перевантажений оператор.
    STD_PRINT("Element at index 1: ", (*complexArray)[1].toString())
    // виведення числа з максимальним модулем.
    STD_PRINT("Max by modulus ", complexArray->MaxByModulus().toString())
    // виведення суми всіх чисел.
    STD_PRINT("Sum all: ", complexArray->SumAll().toString())
    // виведення суми модулів всіх чисел.
    STD_PRINT("Modulus sum all: ", complexArray->ModulusSumAll())
    // виведення добутку всіх чисел.
    STD_PRINT("Production all: ",complexArray->ProductionAll().toString())
    delete complexArray;
    return 0;
}
