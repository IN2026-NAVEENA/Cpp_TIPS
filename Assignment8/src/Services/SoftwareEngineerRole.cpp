#include "Services/SoftwareEngineerRole.hpp"

/*
@brief Determines whether a SoftwareEngineerRole can add an employee.
@return Always returns false, since a SoftwareEngineerRole cannot add employees.
*/
bool SoftwareEngineerRole::canAddEmployee() const {
    return false;
};

/*
@brief Determines whether a SoftwareEngineerRole can remove an employee.
@return Always returns false, since a SoftwareEngineerRole cannot remove employees.
*/
bool SoftwareEngineerRole::canRemoveEmployee() const {
    return false;
}

/*
@brief Determines whether a SoftwareEngineerRole can update position of an employee.
@return Always returns false, since a SoftwareEngineerRole cannot update position of an employees.
*/
bool SoftwareEngineerRole::canUpdatePosition() const {
    return false;
}

/*
@brief Determines whether a SoftwareEngineerRole can update salary of an employee.
@return Always returns false, since a SoftwareEngineerRole cannot update salary of an employees.
*/
bool SoftwareEngineerRole::canUpdateSalary() const {
    return false;
}

/*
@brief Determines whether a SoftwareEngineerRole can view salary of an employee.
@return Always returns false, since a SoftwareEngineerRole cannot view salary of an employees.
*/
bool SoftwareEngineerRole::canViewSalary() const {
    return false;
}

/*
@brief Determines whether a SoftwareEngineerRole can view hardware count of an employee.
@return Always returns false, since a SoftwareEngineerRole cannot view hardware count of an employees.
*/
bool SoftwareEngineerRole::canViewHardwareCount() const {
    return false;
}

/*
@brief Determines whether a SoftwareEngineerRole can update hardware count of an employee.
@return Always returns false, since a SoftwareEngineerRole cannot update hardware count of an employees.
*/
bool SoftwareEngineerRole::canUpdateHardwareCount() const {
    return false;
}