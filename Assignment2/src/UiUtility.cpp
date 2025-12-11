#include "UiUtility.hpp"
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include "Student.hpp"
#include "Validation.hpp"

/*@brief Starts the interactive menu loop for managing student data.*/
void UiUtility::Run()
{
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl
                 << std::setfill(' ') << std::setw(12) << "" << "STUDENT MANAGER" << std::endl
                 << std::setfill('=') << std::setw(40) << "" << std::endl;
    InputStudentData();
    int choice;
    do 
    {
        do 
        {
            std::cout <<"\nWhat would you like to do with the student data" << std::endl
                      <<  "1.Display Student data" << std::endl
                      <<  "2.Search student" << std::endl
                      <<  "3.Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
        } while (!isValidNumber(choice));

        switch (choice) 
        {
            case 1: 
                DisplayAllStudents(); 
                break;
            case 2: 
                SearchStudent(); 
                break;
            case 3: 
                std::cout << "Exiting the application!" << std::endl; 
                break;
        }
    } while (choice != 3);
}

/*@brief Gets the student data from the user and adds them to the collection*/
void UiUtility::InputStudentData()
{
    std::string name;
    int rollNumber, studentRank, numberOfStudents;
    do 
    {
        std::cout << "Enter number of students: ";
        std::cin >> numberOfStudents;
    } while (!isValidNumber(numberOfStudents));

    for (int studentNumber = 1; studentNumber <= numberOfStudents; ++studentNumber) 
    {
        std::cout << "Enter details of student " << studentNumber << std::endl;
        GetValidInput("Name: ", name, isValidName);
        GetValidInput("Roll number: ", rollNumber, isValidNumber);
        GetValidInput("Rank: ", studentRank, isValidNumber);
        studentManager.Add(Student(name, rollNumber, studentRank));
    }
}

/*
@brief Prompt the user for input until it passes validation.
@tparam T The type of the input value
@param prompt The message displayed to the user before input.
@param value Reference to the variable where the input will be stored.
@param validator A function that takes the input value and returns true if valid, false otherwise.
*/
template <typename T, typename Validator>
void UiUtility::GetValidInput(const std::string& prompt, T& value, const Validator& validator) {
    do {
        std::cout << prompt;
        std::cin >> value;
    } while (!validator(value));
}

/*@brief Gets all student data and displays them to the user.*/
void UiUtility::DisplayAllStudents() const
{
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl
                 << std::setfill(' ') << std::setw(12) << "" << "STUDENT DETAILS" << std::endl
                 << std::setfill('=') << std::setw(40) << "" << std::endl;

    for (const auto& student : studentManager.GetAll()) 
    {
        student.Display();
        std::cout << std::setfill('-') << std::setw(40) << "" << std::endl;
    }
}

/*@brief Gets the student name from user and searches for the student data in the collection.*/
void UiUtility::SearchStudent() const
{
    std::string name;
    do 
    {
        std::cout << "Enter student name to search: ";
        std::cin >> name;
    } while (!isValidName(name));

    auto student = studentManager.FindByName(name);
    if (!student) 
    {
        std::cout << "Student not found!" << std::endl;      
    } 
    else 
    {
        std::cout << std::setfill('=') << std::setw(40) << "" << std::endl
            << std::setfill(' ') << std::setw(12) << "" << "STUDENT DETAILS" << std::endl
            << std::setfill('=') << std::setw(40) << "" << std::endl;
        student->Display();
    }   
}