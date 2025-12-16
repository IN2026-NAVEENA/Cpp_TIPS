#pragma once

#include "Repositories/EmployeeRepo.hpp"
#include "IRoleStrategy.hpp"
#include "Models/CreateEmployeeDto.hpp"
#include "Logger/EventLog.hpp"

class EmployeeService {
    public:
        /*
        @brief Constructs an EmployeeService instance with the given attributes.
        @param repo Reference to the EmployeeRepo.
        @param role Unique pointer to the role strategy that defines permissions and allowed actions.
        @param employee Pointer to the current Employee object.
        @param log Reference to the Logger used for logging informational and error messages.
        */
        EmployeeService(EmployeeRepo& repo, std::unique_ptr<IRoleStrategy> role, Employee* employee, Logger& log) 
            : employeeRepo(repo), employeeRole(std::move(role)), employee(employee), logger(log) {}

        /*@brief Prompts for employee details and adds a new employee to the repository.*/
        void AddEmployee();

        /*@brief Prompts for an employee ID and removes an existing employee from the repository.*/
        void RemoveEmployee();

        /*@brief Prompts for an employee ID and new position and updates the position of an existing employee.*/
        void UpdateEmployeePosition();

        /*@brief Prompts for an employee ID and new salary and updates the salary of an existing employee.*/
        void UpdateEmployeeSalary();

        /*@brief Prompts for  new hardware unit and updates the hardware unit of an existing employee.*/
        void UpdateHardwareCount();

        /*@brief Displays employees filtered by category.*/
        void ViewEmployeeByCategory() const;

        /*@brief Displays employees filtered by position.*/
        void ViewEmployeeByPosition() const;

        /*@brief Displays employees filtered by id.*/
        void ViewEmployeeById() const;

        /*@brief Displays the total count of employees.*/
        void ViewEmployeeCount() const;

        /*@brief Displays the total hardware unit count of the employee.*/
        void ViewHardwareCount() const;

    private:
        /*@brief Reference to the EmployeeRepo.*/
        EmployeeRepo& employeeRepo;
        /*@brief Unique pointer to the role strategy that defines permissions and allowed actions.*/
        std::unique_ptr<IRoleStrategy> employeeRole;
        /*@brief Pointer to the current Employee object.*/
        Employee* employee;
        /*@brief Reference to the Logger used for logging informational and error messages.*/
        Logger& logger;

        /*
        @brief Finds an employee by ID.
        @return Pointer to the found Employee object.
        */
        Employee* FindEmployee() const;

        /*
        @brief Displays details of the given employee.
        @param employees Pointer to the employee whose details should be displayed.
        */
        void ViewEmployee(const Employee* employees) const;

        /*
        @brief Creates a new employee instance.
        @param employee Dto containing employee details.
        @return A unique_ptr to the newly created Employee object.
        */
        std::unique_ptr<Employee> CreateEmployee(const CreateEmployeeDto& employee);

        /*
        @brief Collects employee details from user input.
        @return A CreateEmployeeDto containing the employee details.
        */
        CreateEmployeeDto GetEmployeeDetails() const;

        /*
        @brief Converts a position enum value to its string representation.
        @param choice The position to convert.
        @return A string representing the given position.
        */
        Position MapChoiceToPosition(size_t choice) const;

        /*
        @brief Converts a user role enum value to its string representation.
        @param choice The role to convert.
        @return A string representing the given user role.
        */
        UserRole MapChoiceToRole(size_t choice) const;
};