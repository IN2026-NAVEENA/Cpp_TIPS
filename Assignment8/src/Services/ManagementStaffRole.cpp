#include "Services/ManagementStaffRole.hpp"

/*
@brief Determines whether a ManagementStaffRole can add an employee.
@return Always returns true, since a ManagementStaffRole can add employees.
*/
bool ManagementStaffRole::canAddEmployee() const {
    return true;
}

/*
@brief Determines whether a ManagementStaffRole can remove an employee.
@return Always returns true, since a ManagementStaffRole can remove employees.
*/
bool ManagementStaffRole::canRemoveEmployee() const {
    return true;
}

/*
@brief Determines whether a ManagementStaffRole can update position of an employee.
@return Always returns true, since a ManagementStaffRole can update position of an employees.
*/
bool ManagementStaffRole::canUpdatePosition() const {
    return true;
}

/*
@brief Determines whether a SoftwareEngineerRole can update salary of an employee.
@return Always returns true, since a SoftwareEngineerRole can update salary of an employees.
*/
bool ManagementStaffRole::canUpdateSalary() const {
    return true;
}

/*
@brief Determines whether a ManagementStaffRole can view salary of an employee.
@return Always returns true, since a ManagementStaffRole can view salary of an employees.
*/
bool ManagementStaffRole::canViewSalary() const {
    return true;
}

/*
@brief Determines whether a ManagementStaffRole can view hardware count of an employee.
@return Always returns false, since a ManagementStaffRole cannot view hardware count of an employees.
*/
bool ManagementStaffRole::canViewHardwareCount() const {
    return false;
}

/*
@brief Determines whether a ManagementStaffRole can update hardware count of an employee.
@return Always returns false, since a ManagementStaffRole cannot update hardware count of an employees.
*/
bool ManagementStaffRole::canUpdateHardwareCount() const {
    return false;
}