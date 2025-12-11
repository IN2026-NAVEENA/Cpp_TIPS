#pragma once

#include<string>

/*@brief Represent the data model for person.*/
class Person
{
    public:
        /*
        @brief Parameterized constructor that initializes person with name and age.
        @param name The name of the person.
        @param age The age of the person.
        */
        Person(std::string name, int age) : personName(name), personAge(age) {}

        /*@brief Displays the name of the person.*/
        void ShowName() const;

        /*@brief Displays the details of the person like their name and age.*/
        virtual void ShowDetails() const;
        
    protected:
        /*@brief The name of the person.*/
        std::string personName;
        
        /*@brief The age of the person.*/
        int personAge;
};