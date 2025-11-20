#include<iostream>
#include<cmath>
#include "Validation.hpp"

/*
@brief Validates if the user input is a integer.
@return true if input is a integer else false.
*/
bool isValidInteger()
{
    if (std::cin.fail()) 
    {
        std::cout << "Invalid input! Not a valid integer." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
    {
        return true;
    }
}