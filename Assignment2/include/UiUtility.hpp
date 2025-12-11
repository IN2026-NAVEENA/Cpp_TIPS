#pragma once

#include <string>
#include <functional>
#include "StudentManager.hpp"

/*@brief Provides utility methods to manage ui interaction.*/
class UiUtility 
{
    public:
        
        /*
        @brief Constructor that initializes the class with a student manager reference
        @param studentManager Reference to the student manager.
        */
        explicit UiUtility(StudentManager& studentManager) : studentManager(studentManager) {}

        /// @brief Starts the interactive menu loop for managing student data.
        void Run();
        
        /*@brief Gets the student data from the user and adds them to the collection*/
        void InputStudentData();

        /*@brief Gets all student data and displays them to the user.*/
        void DisplayAllStudents() const;

        /*@brief Gets the student name from user and searches for the student data in the collection.*/
        void SearchStudent() const;

        /*
        @brief Prompt the user for input until it passes validation.
        @tparam T The type of the input value
        @param prompt The message displayed to the user before input.
        @param value Reference to the variable where the input will be stored.
        @param validator A function that takes the input value and returns true if valid, false otherwise.
        */
        template <typename T, typename Validator>
        void GetValidInput(const std::string& prompt, T& value, const Validator& validator);

    private: 
        /*@brief Reference to the student manager.*/
        StudentManager& studentManager;
};