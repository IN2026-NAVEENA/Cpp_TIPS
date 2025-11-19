#include<iostream>
#include<string>
#include<vector>
#include "Student.hpp"
#include "Validation.hpp"
#include "UiUtility.hpp"

/// @brief Starts the interactive menu loop for managing student data.
void UiUtility::Run()
{
    std::cout << "========================================" << std::endl
                 << "           STUDENT MANAGER" << std::endl
                 << "========================================" << std::endl;
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

/// @brief Gets the student data from the user and adds them to the collection
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
        do 
        {
            std::cout << "Name: ";
            std::cin >> name;
        } while (!isValidName(name));

        do 
        {
            std::cout << "Roll number: ";
            std::cin >> rollNumber;
        } while (!isValidNumber(rollNumber));

        do 
        {
            std::cout << "Rank: ";
            std::cin >> studentRank;
        } while (!isValidNumber(studentRank));
        studentManager.Add(Student(name, rollNumber, studentRank));
    }
}

/// @brief Gets all student data and displays them to the user.
void UiUtility::DisplayAllStudents() const
{
    std::cout << "========================================" << std::endl
                 << "           STUDENT DETAILS" << std::endl
                 << "========================================" << std::endl;

    for (const auto& student : studentManager.GetAll()) 
    {
        student.Display();
        std::cout << "----------------------------------------" << std::endl;
    }
}

/// @brief Gets the student name from user and searches for the student data in the collection.
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
        student->Display();
    }   
}