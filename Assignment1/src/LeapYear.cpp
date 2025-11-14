#include<iostream>
#include <cmath>
#define YEAR_LENGTH 4

/// @brief Checks if the given year is a leap year.
/// @param year An integer representing the year.
/// @return true if the year is leap year else false.
bool isLeapYear(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

/// @brief Entry point of the program.
int main()
{
    int year;   
    bool isExitRequired = false;

    while(!isExitRequired)
    {
        std::cout << "Enter a year to check if it is a leap year or not: "; 
        std::cin >> year;

        if (std::cin.fail()) 
        {
            std::cout<< "Invalid input! Not an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (year != 0 && (int)log10(abs(year)) + 1 == YEAR_LENGTH)
        {
            isExitRequired = true;
        }
        else
        {
            std::cout << "Invalid input! Not a valid year.\n";
        }
    }

    if(isLeapYear(year))
    {
        std::cout << "The given year " << year << " is a leap year.\n";
    }
    else
    {
        std::cout << "The given year " << year << " is not a leap year.\n";
    }
    return 0;
}