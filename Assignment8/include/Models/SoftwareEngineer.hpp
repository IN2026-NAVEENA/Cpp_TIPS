#pragma once

#include "Employee.hpp"
class SoftwareEngineer : public Employee {
    public:
        /*
        @brief Constructs a new SoftwareEngineer object with the specified attributes.
        @param id The ID assigned to the employee.
        @param name The name of the employee.
        @param password The password of the employee.
        @param role The role assigned to the employee (e.g., ManagementStaff, HardwareEngineer, SoftwareEngineer).
        @param position The position of the employee (e.g., Junior, Senior, Lead).
        @param salary The salary of the employee.
        */
        SoftwareEngineer(int id, const std::string& name, const std::string& password, UserRole role, Position position, double salary) 
            : Employee(id, name, password, role, position, salary){}
};