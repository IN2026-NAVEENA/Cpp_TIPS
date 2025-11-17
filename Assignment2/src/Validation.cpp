#include<iostream>
#include<cmath>
#include<string>
#include "Validation.hpp"

/*
@brief Validates if the user input is positive number.
@param number Number to be validated.
@return true if input is a positive number else false.
*/
bool isValidNumber(int number)
{
    if (std::cin.fail()) 
    {
        std::cout << "Invalid input! Not a valid number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (number < 0)
    {
        std::cout << "Invalid input! Enter a positive number.\n";
        return false;
    }
    else if (number == 0)
    {
        std::cout << "Invalid input! Number cannot be zero.\n";
        return false;
    }
    else
    {
        return true;
    }
}

/*
@brief Validates if the user input is name with alphabets.
@param name Name to be validated.
@return true if valid name else false.
*/
bool isValidName(const std::string& name) 
{
    for (char ch : name) {
        if (!std::isalpha(ch)) 
        {
            std::cout << "Invalid input! Name cannot have number or special character.\n";
            return false;
        }
    }
    return true;
}