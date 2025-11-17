#pragma once
#include "StudentManager.hpp"

/// @brief Provides utility methods to manage ui interaction.
class UiUtility 
{
    /// @brief Reference to the student manager.
    StudentManager& studentManager;

    /// @brief Gets all student data and displays them to the user.
    void DisplayAllStudents() const;

    /// @brief Gets the student name from user and searches for the student data in the collection.
    void SearchStudent() const;

    /// @brief Gets the student data from the user and adds them to the collection
    void InputStudentData();

    public:
        
        /*
        @brief Constructor that initializes the class with a student manager reference
        @param studentManager Reference to the student manager.
        */
        explicit UiUtility(StudentManager& studentManager) : studentManager(studentManager) {}

        /// @brief Starts the interactive menu loop for managing student data.
        void Run();
};