#include<iostream>
#include <stddef.h>
#include<cstring>
#include<algorithm>
#include<cctype>

/*
@brief Calculates the number of bytes required to store the name.
@param name Character array representing the name.
@return The number of bytes to store the name.
*/
size_t calculateBytes(char name[])
{
    return strlen(name) * sizeof(char) + 1;
}

/*
@brief Sorts the name in alphabetical order.
@param name Character array representing the name.
@return A pointer to the sorted character array.
*/
void sortName(char name[])
{
    std::sort(name,name + strlen(name));
}

/*
@brief Converts each character of the string to lower case.
@param name Character array representing the name.
@return A pointer to the modified character array with all characters in lowercase.
*/
void toLowerCase(char name[])
{
    for(int index = 0; name[index] != '\0'; ++index)
    {
        name[index] = tolower(name[index]);
    }
}

/// @brief Entry point of the program.
int main()
{
    char name[] = "Naveena";

    std::cout << "The number of bytes required to store " << name << " is " << calculateBytes(name) << std::endl;

    toLowerCase(name);
    sortName(name);

    std::cout << "The alphabetic sorted order is ";

    for(int index = 0; name[index] != '\0'; ++index)
    {
        std::cout << name[index] << " ";
    }
    
    return 0;
}