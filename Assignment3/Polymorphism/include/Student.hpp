#pragma once

#include<string>
#include "Person.hpp"

/*@brief Represent the data model for student.*/
class Student : public Person
{
    public:
        /*
        @brief Parameterized constructor that initializes student with name, age and qualification.
        @param name The name of the student.
        @param age The age of the student.
        @param qualification The qualification of the student.
        */
        Student(const std::string& name, int age,const std::string& qualification) 
            : Person(name, age), studentQualification(qualification){}

        /*@brief Displays the details of the student like their name, age and qualification.*/
        void ShowDetails() const override;

    private:
        /*@brief The qualification of the student.*/
        std::string studentQualification;
};