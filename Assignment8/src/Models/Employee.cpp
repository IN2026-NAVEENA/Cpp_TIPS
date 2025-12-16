#include "Models/Employee.hpp"

/*
@brief Gets the ID of the employee.
@return The employee's  ID.
*/
int Employee::GetId() const {
    return employeeId;
}

/*
@brief Gets the name of the employee.
@return A constant reference to the employee's name.
*/
const std::string& Employee::GetName() const {
    return employeeName;
}

/*
@brief Gets the username of the employee.
@return The employee's username as a string.
*/
std::string Employee::GetUserName() const {
    return std::to_string(employeeId) + "_" + employeeName;
}

/*
@brief Gets the password associated with the employee.
@return A constant reference to the employee's password.
*/
const std::string& Employee::GetPassword() const {
    return employeePassword;
}

/*
@brief Gets the role assigned to the employee.
@return The employee's role (e.g., ManagementStaff, HardwareEngineer, SoftwareEngineer).
*/
UserRole Employee::GetRole() const {
    return employeeRole;
}

/*
@brief Gets the position of the employee.
@return The employee's position (e.g., Junior, Senior, Lead).
*/
Position Employee::GetPosition() const {
    return employeePosition;
}

/*
@brief Gets the salary of the employee.
@return The employee's salary.
*/
double Employee::GetSalary() const {
    return employeeSalary;
}

/*
@brief Sets the name of the employee.
@param name The new name to assign to the employee.
*/
void Employee::SetName(const std::string& name) {
    employeeName = name;
}

/*
@brief Sets the password for the employee.
@param password The new password to assign to the employee.
*/
void Employee::SetPassword(const std::string& password) {
    employeePassword = password;
}

/*
@brief Sets the role of the employee.
@param role The new role to assign (e.g., ManagementStaff, HardwareEngineer, SoftwareEngineer).
*/
void Employee::SetRole(UserRole role) {
    employeeRole = role;
}

/*
@brief Sets the position level of the employee.
@param position The new position to assign (e.g., Junior, Senior, Lead).
*/
void Employee::SetPosition(Position position) {
    employeePosition = position;
}

/*
@brief Sets the salary of the employee.
@param salary The new salary value to assign.
*/
void Employee::SetSalary(double salary){
    employeeSalary = salary;
}