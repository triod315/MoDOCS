/*
 * This file is part of MoDOCS_Task3 which is released under MIT License.
 * Created by triod315 on 10/31/21, 12:44 PM
 * Copyright (c) 2021.
 */

#include <iostream>
//#include "ComplexNumber.h"
#include "ComplexArray.h"

#define STD_PRINT(text, value) std::cout<<text<<value<<std::endl;

int main() {
    ComplexArray* complexArray = new ComplexArray(0);
    complexArray->AddToEnd(1,1);
    complexArray->AddToEnd(2,3);
    complexArray->AddToEnd(5,8);
    complexArray->printAllItems();

    complexArray->printItemAt(2);

    STD_PRINT("Max by modulus ", complexArray->MaxByModulus().toString())
    STD_PRINT("Sum all: ", complexArray->SumAll().toString())
    STD_PRINT("Modulus sum all: ", complexArray->ModulusSumAll())
    STD_PRINT("Production all: ",complexArray->ProductionAll().toString())

    delete complexArray;
    return 0;
}
