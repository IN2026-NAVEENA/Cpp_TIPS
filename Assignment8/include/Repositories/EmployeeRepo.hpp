#pragma once

#include<memory>
#include<vector>
#include "Models/Employee.hpp"

class EmployeeRepo {
    public:
        /*
        @brief Generates the employee id of the new employee.
        @return The new employee id.
        */
        static size_t GenerateEmployeeId();

        /*
        @brief Authenticates an employee using their username and password.
        @param name The username of the employee.
        @param password The password of the employee.
        @return A pointer to the authenticated Employee object if the credentials match; otherwise, returns nullptr.
        */
        Employee* Authenticate(const std::string& name, const std::string& password);

        /*
        @brief Retrieves all employees stored in the repository.
        @return A constant reference to the vector containing unique pointers to employee objects.
        */
        const std::vector<std::unique_ptr<Employee>>& GetAllEmployees() const;

        /*
        @brief Gets the total number of employees stored in the repository.
        @return The number of employees currently held in the vector.
        */
        const size_t GetEmployeeCount() const;

        /*
        @brief Finds an employee in the repository by their id.
        @param id The id of the employee.
        @return A pointer to the Employee object if found; otherwise, returns nullptr.
        */
        Employee* FindEmployeeById(int id) const;

        /*
        @brief Adds a new employee to the repository.
        @param employee New employee to be added to the repository.
        */
        void AddEmployee(std::unique_ptr<Employee>&& employee);

        /*
        @brief Removes an employee from the repository.
        @param id The id of the employee who will be removed.
        @return True if the employee is removed; otherwise, returns false.
        */
        bool RemoveEmployee(int id);
        
        /*
        @brief Updates the position of the employee.
        @param employee A pointer to the Employee object whose position will be updated.
        @param position The new Position value to assign to the employee.
        */
        void UpdateEmployeePosition(Employee* employee, Position position);

        /*
        @brief Updates the salary of the employee.
        @param employee A pointer to the Employee object whose salary will be updated.
        @param salary The new Position value to assign to the employee.
        */
        void UpdateEmployeeSalary(Employee* employee, double salary);

    private:
        /*@brief Vector holding all employees managed by the repository.*/
        std::vector<std::unique_ptr<Employee>> employees_;
        
        /*@brief Counter to assign unique IDs to employees.*/
        inline static size_t nextId = 1;
};