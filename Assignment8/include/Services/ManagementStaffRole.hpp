#pragma once

#include "IRoleStrategy.hpp"

class ManagementStaffRole : public IRoleStrategy {
    public:
        /*
        @brief Determines whether a ManagementStaffRole can add an employee.
        @return Always returns true, since a ManagementStaffRole can add employees.
        */
        bool canAddEmployee() const override;

        /*
        @brief Determines whether a ManagementStaffRole can remove an employee.
        @return Always returns true, since a ManagementStaffRole can remove employees.
        */
        bool canRemoveEmployee() const override;

        /*
        @brief Determines whether a ManagementStaffRole can update position of an employee.
        @return Always returns true, since a ManagementStaffRole can update position of an employees.
        */
        bool canUpdatePosition() const override;

        /*
        @brief Determines whether a SoftwareEngineerRole can update salary of an employee.
        @return Always returns true, since a SoftwareEngineerRole can update salary of an employees.
        */
        bool canUpdateSalary() const override;
        
        /*
        @brief Determines whether a ManagementStaffRole can view salary of an employee.
        @return Always returns true, since a ManagementStaffRole can view salary of an employees.
        */
        bool canViewSalary() const override;

        /*
        @brief Determines whether a ManagementStaffRole can view hardware count of an employee.
        @return Always returns false, since a ManagementStaffRole cannot view hardware count of an employees.
        */
        bool canViewHardwareCount() const override;

        /*
        @brief Determines whether a ManagementStaffRole can update hardware count of an employee.
        @return Always returns false, since a ManagementStaffRole cannot update hardware count of an employees.
        */
        bool canUpdateHardwareCount() const override;
};