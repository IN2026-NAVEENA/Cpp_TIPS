#pragma once

#include "Employee.hpp"

class HardwareEngineer : public Employee {
    public:
        /*
        @brief Constructs a new HardwareEngineer object with the specified attributes.
        @param id The ID assigned to the employee.
        @param name The name of the employee.
        @param password The password of the employee.
        @param role The role assigned to the employee (e.g., ManagementStaff, HardwareEngineer, SoftwareEngineer).
        @param position The position of the employee (e.g., Junior, Senior, Lead).
        @param salary The salary of the employee.
        */
        HardwareEngineer(int id, const std::string& name, const std::string& password, UserRole role, Position position, double salary, int hardwareCount) 
            : Employee(id, name, password, role, position, salary), hardwareCount_(hardwareCount) {}
        
        /*
        @brief Gets the hardware units count of the employee.
        @return Hardware units count of the employee.
        */
        int GetHardwareCount() const;

        /*
        @brief Sets the hardware count for the employee.
        @param hardwareCount The new hardware count to assign to the employee.
        */
        void SetHardwareCount(int hardwareCount);

    private:
        /*@brief The number of hardware items assigned to the employee.*/
        int hardwareCount_;
};

