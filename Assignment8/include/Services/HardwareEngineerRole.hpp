#pragma once

#include "IRoleStrategy.hpp"

class HardwareEngineerRole : public IRoleStrategy {
    public:
        /*
        @brief Determines whether a HardwareEngineerRole can add an employee.
        @return Always returns false, since a HardwareEngineerRole cannot add employees.
        */
        bool canAddEmployee() const override;

        /*
        @brief Determines whether a HardwareEngineerRole can remove an employee.
        @return Always returns false, since a HardwareEngineerRole cannot remove employees.
        */
        bool canRemoveEmployee() const override;

        /*
        @brief Determines whether a HardwareEngineerRole can update position of an employee.
        @return Always returns false, since a HardwareEngineerRole cannot update position of an employees.
        */
        bool canUpdatePosition() const override;

        /*
        @brief Determines whether a HardwareEngineerRole can update salary of an employee.
        @return Always returns false, since a HardwareEngineerRole cannot update salary of an employees.
        */
        bool canUpdateSalary() const override;
        
        /*
        @brief Determines whether a HardwareEngineerRole can view salary of an employee.
        @return Always returns false, since a HardwareEngineerRole cannot view salary of an employees.
        */
        bool canViewSalary() const override;

        /*
        @brief Determines whether a HardwareEngineerRole can view hardware count of an employee.
        @return Always returns true, since a HardwareEngineerRole can view hardware count of an employees.
        */
        bool canViewHardwareCount() const override;

        /*
        @brief Determines whether a HardwareEngineerRole can update hardware count of an employee.
        @return Always returns true, since a HardwareEngineerRole can update hardware count of an employees.
        */
        bool canUpdateHardwareCount() const override;
};