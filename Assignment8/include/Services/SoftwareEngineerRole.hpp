#pragma once

#include "IRoleStrategy.hpp"

class SoftwareEngineerRole : public IRoleStrategy {
    public:
        /*
        @brief Determines whether a SoftwareEngineerRole can add an employee.
        @return Always returns false, since a SoftwareEngineerRole cannot add employees.
        */
        bool canAddEmployee() const override;

        /*
        @brief Determines whether a SoftwareEngineerRole can remove an employee.
        @return Always returns false, since a SoftwareEngineerRole cannot remove employees.
        */
        bool canRemoveEmployee() const override;

        /*
        @brief Determines whether a SoftwareEngineerRole can update position of an employee.
        @return Always returns false, since a SoftwareEngineerRole cannot update position of an employees.
        */
        bool canUpdatePosition() const override;

        /*
        @brief Determines whether a SoftwareEngineerRole can update salary of an employee.
        @return Always returns false, since a SoftwareEngineerRole cannot update salary of an employees.
        */
        bool canUpdateSalary() const override;
        
        /*
        @brief Determines whether a SoftwareEngineerRole can view salary of an employee.
        @return Always returns false, since a SoftwareEngineerRole cannot view salary of an employees.
        */
        bool canViewSalary() const override;

        /*
        @brief Determines whether a SoftwareEngineerRole can view hardware count of an employee.
        @return Always returns false, since a SoftwareEngineerRole cannot view hardware count of an employees.
        */
        bool canViewHardwareCount() const override;

        /*
        @brief Determines whether a SoftwareEngineerRole can update hardware count of an employee.
        @return Always returns false, since a SoftwareEngineerRole cannot update hardware count of an employees.
        */
        bool canUpdateHardwareCount() const override;
};