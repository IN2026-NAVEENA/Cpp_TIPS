#include<iostream>

/*
@brief Swaps the values of two integers using references.
@param firstNumber Reference of first number
@param secondNumber Reference of second number
*/
void swapNumber(int& firstNumber, int& secondNumber)
{
    int tempNumber = firstNumber;
    firstNumber = secondNumber;
    secondNumber = tempNumber;
}

/// @brief Entry point of the program.
int main()
{
    int firstNumber = 10;
    int secondNumber = 20;
    std::cout << "Before Swapping" << std::endl;
    std::cout << "The value of first number is " << firstNumber << " and second number is " << secondNumber << std::endl;

    swapNumber(firstNumber,secondNumber);

    std::cout << "After Swapping" << std::endl;
    std::cout << "The value of first number is " << firstNumber << " and second number is " << secondNumber << std::endl;

    return 0;
}