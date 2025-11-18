#include<iostream>
#include "Subject.hpp"

/*
@brief Overloads the + operator to combine two Subject objects.
@param subject The other Subject object to be added.
@return A new Subject object representing the sum of the two.
*/
Subject Subject::operator+(const Subject& subject)
{
    Subject total;
    total.subjectMark = this->subjectMark + subject.subjectMark;
    return total;
}

/// @brief Displays the total mark obtained by the student.
void Subject::ShowTotalMark() const
{
    std::cout << "The total mark of the student is " << subjectMark << std::endl;
}