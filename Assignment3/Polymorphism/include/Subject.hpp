#pragma once
#include<string>

/*@brief Represent the data model for subject.*/
class Subject
{
    public:
        /*@brief Constructor to initialize subject with default values.*/
        Subject() : subjectName(""), subjectMark(0) {}
        
        /*
        @brief Parameterized constructor that initializes subject with name and mark.
        @param name The name of the subject.
        @param mark The mark of the subject.
        */
        Subject(const std::string& name, int mark) : subjectName(name), subjectMark(mark) {}

        /*
        @brief Overloads the + operator to combine two Subject objects.
        @param subject The other Subject object to be added.
        @return A new Subject object representing the sum of the two.
        */
        Subject operator+(const Subject& subject);

        /*@brief Displays the total mark obtained by the student.*/
        void ShowTotalMark() const;
    
    private:
        /*@brief The name of the subject.*/
        std::string subjectName;
        
        /*@brief The mark of the subject.*/
        int subjectMark;
};