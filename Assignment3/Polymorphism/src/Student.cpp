#include<iostream>
#include "Person.hpp"
#include "Student.hpp"

/// @brief Displays the details of the student like their name, age and qualification.
void Student::ShowDetails() const
{
        std::cout
                 << "      STUDENT DETAILS" << std::endl
                 << "==========================" << std::endl;
    std::cout << "The name is " << personName << std::endl;
    std::cout << "Age is " << personAge << std::endl;
    std::cout << "Qualification is " << studentQualification << "\n" << std::endl;
}