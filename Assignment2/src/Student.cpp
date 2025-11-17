#include<iostream>
#include<vector>
#include "Student.hpp"

/*
@brief Gets the name of the student
@return Name of the student
*/
std::string Student::getName() const 
{ 
    return name_; 
}

/// @brief Displays the details of the student
void Student::Display() const 
{
    std::cout << "Name       : " << name_ << '\n'
              << "Roll Number: " << rollNumber_ << '\n'
              << "Rank       : " << rank_ << '\n';
}
