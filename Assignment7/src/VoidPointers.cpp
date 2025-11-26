#include <iostream>

/// @brief Enumeration to describe numeric types for the Add function.
enum Datatype {
    Int,
    Float,
    Double,
};

/*
@brief Adds two numbers of the specified datatype.
@param firstNumber Pointer to the first numeric value.
@param secondNumber Pointer to the second numeric value.
@param datatype Specifies the underlying numeric type.
@return The sum of the two values.
*/
double Add(void* firstNumber, void* secondNumber, Datatype datatype) {
    switch(datatype) {
        case Int:
            return *(int*)firstNumber + *(int*)secondNumber;
        case Float:
            return *(float*)firstNumber + *(float*)secondNumber;
        case Double:
            return *(double*)firstNumber + *(double*)secondNumber;
    }
}

/// @brief Entry point of the program.
int main() {
    int a = 3, b = 4;
    double result = Add(&a, &b, Int);
    std::cout << "Sum of integers: " << result << std::endl;

    float c = 7.9f, d = 9.8f;
    result = Add(&c, &d, Float);
    std::cout << "Sum of float: " << result << std::endl;

    double e = 2.5, f = 3.7;
    result = Add(&e, &f, Double);
    std::cout << "Sum of double: " << result << std::endl;

    return 0;
}