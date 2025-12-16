#include "Services/HardwareEngineerRole.hpp"

/*
@brief Determines whether a HardwareEngineerRole can add an employee.
@return Always returns false, since a HardwareEngineerRole cannot add employees.
*/
bool HardwareEngineerRole::canAddEmployee() const {
    return false;
}

/*
@brief Determines whether a HardwareEngineerRole can remove an employee.
@return Always returns false, since a HardwareEngineerRole cannot remove employees.
*/
bool HardwareEngineerRole::canRemoveEmployee() const {
    return false;
}

/*
@brief Determines whether a HardwareEngineerRole can update position of an employee.
@return Always returns false, since a HardwareEngineerRole cannot update position of an employees.
*/
bool HardwareEngineerRole::canUpdatePosition() const {
    return false;
}

/*
@brief Determines whether a HardwareEngineerRole can update salary of an employee.
@return Always returns false, since a HardwareEngineerRole cannot update salary of an employees.
*/
bool HardwareEngineerRole::canUpdateSalary() const {
    return false;
}

/*
@brief Determines whether a HardwareEngineerRole can view salary of an employee.
@return Always returns false, since a HardwareEngineerRole cannot view salary of an employees.
*/
bool HardwareEngineerRole::canViewSalary() const {
    return false;
}

/*
@brief Determines whether a HardwareEngineerRole can view hardware count of an employee.
@return Always returns true, since a HardwareEngineerRole can view hardware count of an employees.
*/
bool HardwareEngineerRole::canViewHardwareCount() const {
    return true;
}

/*
@brief Determines whether a HardwareEngineerRole can update hardware count of an employee.
@return Always returns true, since a HardwareEngineerRole can update hardware count of an employees.
*/
bool HardwareEngineerRole::canUpdateHardwareCount() const {
    return true;
}