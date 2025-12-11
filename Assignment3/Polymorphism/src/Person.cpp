#include "Person.hpp"
#include<iostream>
#include<iomanip>

/*@brief Displays the name of the person.*/
void Person::ShowName() const
{
    std::cout
                 << "       PERSON NAME" << std::endl
                 << std::setfill('=') << std::setw(25) << "" << std::endl;
    std::cout << "The name is " << personName << "\n" << std::endl;
}

/*@brief Displays the details of the person like their name and age.*/
void Person::ShowDetails() const
{
    std::cout 
                 << "      PERSON DETAILS" << std::endl
                 << std::setfill('=') << std::setw(25) << "" << std::endl;
    std::cout << "The name is " << personName << std::endl;
    std::cout << "Age is " << personAge << "\n" << std::endl;
}