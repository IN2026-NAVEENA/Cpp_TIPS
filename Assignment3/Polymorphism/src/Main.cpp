#include<iostream>
#include "Person.hpp"
#include "Student.hpp"
#include "Subject.hpp"

/*@brief Entry point of the program.*/
int main()
{
    Person person("Naveena", 15);
    Student student("Vibithaa", 21, "BE.EEE");

    person.ShowName();
    person.ShowDetails();
    student.ShowName();
    student.ShowDetails();
    
    Subject english("English", 92);
    Subject maths("Maths", 97);
    Subject totalMark;

    totalMark = english + maths;
    totalMark.ShowTotalMark();
    
    return 0;
}