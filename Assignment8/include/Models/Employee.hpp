#pragma once

#include<string>
#include "Enums/Position.hpp"
#include "Enums/UserRole.hpp"

class Employee {
    public:
        /*
        @brief Constructs a new Employee object with the specified attributes.
        @param id The ID assigned to the employee.
        @param name The name of the employee.
        @param password The password of the employee.
        @param role The role assigned to the employee (e.g., ManagementStaff, HardwareEngineer, SoftwareEngineer).
        @param position The position of the employee (e.g., Junior, Senior, Lead).
        @param salary The salary of the employee.
        */
        Employee(int id, const std::string& name, const std::string& password, UserRole role, Position position, double salary) :
            employeeId(id), employeeName(name), employeePassword(password), employeeRole(role), employeePosition(position), employeeSalary(salary) {}
        
        /*
        @brief Gets the ID of the employee.
        @return The employee's  ID.
        */
        int GetId() const;

        /*
        @brief Gets the name of the employee.
        @return A constant reference to the employee's name.
        */
        const std::string& GetName() const;

        /*
        @brief Gets the username of the employee.
        @return The employee's username as a string.
        */
        std::string GetUserName() const;

        /*
        @brief Gets the password associated with the employee.
        @return A constant reference to the employee's password.
        */
        const std::string& GetPassword() const;

        /*
        @brief Gets the role assigned to the employee.
        @return The employee's role (e.g., ManagementStaff, HardwareEngineer, SoftwareEngineer).
        */
        UserRole GetRole() const;

        /*
        @brief Gets the position of the employee.
        @return The employee's position (e.g., Junior, Senior, Lead).
        */
        Position GetPosition() const;

        /*
        @brief Gets the salary of the employee.
        @return The employee's salary.
        */
        double GetSalary() const;

        /*
        @brief Sets the name of the employee.
        @param name The new name to assign to the employee.
        */
        void SetName(const std::string& name);

        /*
        @brief Sets the password for the employee.
        @param password The new password to assign to the employee.
        */
        void SetPassword(const std::string& password);

        /*
        @brief Sets the role of the employee.
        @param role The new role to assign (e.g., ManagementStaff, HardwareEngineer, SoftwareEngineer).
        */
        void SetRole(UserRole role);

        /*
        @brief Sets the position of the employee.
        @param position The new position to assign (e.g., Junior, Senior, Lead).
        */
        void SetPosition(Position position);

        /*
        @brief Sets the salary of the employee.
        @param salary The new salary value to assign.
        */
        void SetSalary(double salary);

        /*@brief Virtual destructor for the Employee class.*/
        virtual ~Employee() = default;

    protected:
        /*@brief The id of the employee.*/
        int employeeId;

        /*@brief The name of the employee.*/
        std::string employeeName;

        /*@brief The password of the employee.*/
        std::string employeePassword;

        /*@brief The role of the employee.*/
        UserRole employeeRole;

        /*@brief The position of the employee.*/
        Position employeePosition;

        /*@brief The salary of the employee.*/
        double employeeSalary;
};