#include<iostream>
using namespace std;

/// @brief Swaps the values of two integers using references.
/// @param firstNumber Refernece of first number
/// @param secondNumber Refernece of second number
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
    cout << "Before Swapping\n";
    cout << "The value of first number is " << firstNumber << " and second number is " << secondNumber ;

    swapNumber(firstNumber,secondNumber);

    cout << "\nAfter Swapping\n";
    cout << "The value of first number is " << firstNumber << " and second number is " << secondNumber ;

    return 0;
}