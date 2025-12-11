#include "Student.hpp"
#include<vector>
#include<iostream>

/*
@brief Gets the name of the student
@return Name of the student
*/
const std::string& Student::GetName() const 
{ 
    return name_; 
}

/*@brief Displays the details of the student*/
void Student::Display() const 
{
    std::cout << "Name       : " << name_ << '\n'
              << "Roll Number: " << rollNumber_ << '\n'
              << "Rank       : " << rank_ << std::endl;
}
