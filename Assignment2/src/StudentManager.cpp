#include "StudentManager.hpp"
#include<vector>
#include<optional>

/*
@brief  Adds a new student to the collection.
@param s Student to be added to the collection.
*/
void StudentManager::Add(Student&& student) 
{ 
    students_.emplace_back(std::move(student)); 
}

/*
@brief Searches for a student by name in the student collection.
@param name Name of the student to search.
@return Student data if match found else returns nullopt.
*/
std::optional<Student> StudentManager::FindByName(const std::string& name) const
{
    for(const auto& student: students_)
    {
        if(student.GetName() == name)
        {
            return student;
        }
    }
    return std::nullopt;
}

/*
@brief Gets all the student data in the collection.
@return Collection of student data.
*/
const std::vector<Student>& StudentManager::GetAll() const
{ 
    return students_; 
}