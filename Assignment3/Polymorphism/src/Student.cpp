#include "Student.hpp"
#include<iostream>
#include<iomanip>
#include "Person.hpp"

/*@brief Displays the details of the student like their name, age and qualification.*/
void Student::ShowDetails() const
{
        std::cout
                 << "      STUDENT DETAILS" << std::endl
                 << std::setfill('=') << std::setw(25) << "" << std::endl;
    std::cout << "The name is " << personName << std::endl;
    std::cout << "Age is " << personAge << std::endl;
    std::cout << "Qualification is " << studentQualification << "\n" << std::endl;
}