#include <functional>
#include <iostream>

/*
@brief Adds two integers.
@param firstNumber The first integer to add.
@param secondNumber The second integer to add.
@return The sum of the two integers.
*/
int add(int firstNumber, int secondNumber) {
    return firstNumber + secondNumber;
}

/*
@brief Prints the result of the add function. 
@param addFunction A function that takes two integers and returns an integer.
@param firstNumber The first integer input.
@param secondNumber The second integer input.
*/
void printResult(const std::function<int()>& addFunction, int firstNumber, int secondNumber) {
    std::cout << "The sum of: " << firstNumber << " and " << secondNumber << " is " << addFunction() << std::endl;
}

/*@brief Entry point of the program.*/
int main() {
    int firstNumber = 3, secondNumber = 4;

    printResult(
        [firstNumber, secondNumber]() {
            return add(firstNumber, secondNumber);
        },
        firstNumber, secondNumber
    );
}
