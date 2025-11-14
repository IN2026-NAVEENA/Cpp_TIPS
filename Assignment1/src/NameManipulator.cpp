#include<iostream>
#include<cstring>
#include<algorithm>
#include<cctype>

/// @brief Calculates the number of bytes required to store the name.
/// @param name Character array representing the name.
/// @return The number of bytes to store the name.
int calculateBytes(char name[])
{
    return strlen(name) * sizeof(char);
}

/// @brief Sorts the name in alphabetical order.
/// @param name Character array representing the name.
/// @return A pointer to the sorted character array.
char* sortName(char name[])
{
    std::sort(name,name + strlen(name));
    return name;
}

/// @brief Converts each character of the string to lower case.
/// @param name Character array representing the name.
/// @return A pointer to the modified character array with all characters in lowercase.
char* toLowerCase(char name[])
{
    for(int i = 0; name[i] != '\0'; ++i)
    {
        name[i] = tolower(name[i]);
    }
    return name;
}

/// @brief Entry point of the program.
int main()
{
    char name[] = "Naveena";

    std::cout << "The number of bytes required to store " << name << " is " << calculateBytes(name) << std::endl;

    toLowerCase(name);
    sortName(name);

    std::cout << "The alpabetic sorted order is ";

    for(int i = 0; name[i] != '\0'; ++i)
    {
        std::cout << name[i] << " ";
    }

    return 0;
}