#include<stdio.h>
#include "Factorial.h"

/*
@brief Computes the factorial of a non-negative integer.
@param number The number for which the factorial is computed.
@return The factorial of the input number.
*/
unsigned int Factorial(unsigned int number) {
    if(number == 1) {
        return 1;
    }
    return number * Factorial(number-1);
}