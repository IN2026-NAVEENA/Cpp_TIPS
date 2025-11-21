#include<iostream>
#include<string>

/*
@brief Adds two values of type T.
@tparam T The type of the values to be added.
@param firstValue The first operand.
@param secondValue The second operand.
@return The sum of the two input values.
*/
template <typename T> T AddLiterals(T firstValue, T secondValue)
{
    return firstValue + secondValue;
}

/// @brief Entry point of the program.
int main()
{
    std::cout << "The sum of 3 and 4 is: " << AddLiterals(3,4) << std::endl;
    std::cout << "The sum of 5.6 and 7.2 is: " << AddLiterals(5.6f, 7.2f) << std::endl;
    std::cout << "The sum of 8.22222 and 1.77354 is: " << AddLiterals(8.22222, 1.77354) << std::endl;
    std::cout << "The concatenated result of adding Hello and World is: " << AddLiterals(std::string("Hello"), std::string("World")) << std::endl;
    return 0;
}