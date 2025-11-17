#pragma once
#include "Student.hpp"
#include <vector>
#include <optional>

/// @brief Manages the students data and provides methods to add, retrieve and search student data.
class StudentManager 
{
    /// @brief Stores the list of student records. 
    std::vector<Student> students;

    public:
        /*
        @brief  Adds a new student to the collection.
        @param s Student to be added to the collection.
        */
        void Add(Student s);

        /*
        @brief Searches for a student by name in the student collection.
        @param name Name of the student to search.
        @return Student data if match found else returns nullopt.
        */
        std::optional<Student> FindByName(const std::string& name) const;

        /*
        @brief Gets all the student data in the collection.
        @return Collection of student data.
        */
        const std::vector<Student>& GetAll() const;
};