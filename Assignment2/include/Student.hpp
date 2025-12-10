#pragma once

#include<string>
#include<vector>

/*@brief Represent the data model for student.*/
class Student
{
    public:
        /*
        @brief Initializes a student with name, roll number, and rank.
        @param name Name of the student.
        @param rollNumber Roll number of the student.
        @param rank Rank of the student.
        */
        Student(const std::string& name, int rollNumber, int rank)
            :name_(name), rollNumber_(rollNumber), rank_(rank){}

        /*
        @brief Gets the name of the student
        @return Name of the student
        */
        const std::string& GetName() const;

        /*@brief Displays the details of the student*/
        void Display() const;

    private:
        /*@brief Name of the student.*/
        std::string name_;

        /*@brief Roll number of the student*/
        int rollNumber_;
        
        /* @brief Rank of the student*/
        int rank_;
};