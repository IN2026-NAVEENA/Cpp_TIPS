#include "Services/AuthService.hpp"
#include<iostream>
#include "Services/IRoleStrategy.hpp"
#include "Services/ManagementStaffRole.hpp"
#include "Services/HardwareEngineerRole.hpp"
#include "Services/SoftwareEngineerRole.hpp"
#include "Exceptions/EmployeeManagementException.hpp"
#include "Logger/EventLog.hpp"

/*
@brief Authenticate an employee and create an EmployeeService.
@param name The username of the employee trying to log in.
@param password The password of the employee.
@return A unique_ptr to an EmployeeService instance for the authenticated employee.
*/
std::unique_ptr<EmployeeService> AuthService::Login(const std::string& name, const std::string& password) {
    Employee* employee = employeeRepo.Authenticate(name,password);

    if(employee == nullptr) {
        logger.Log(LogLevel::Error, "9003-Login Failed");
        throw EmployeeManagementException(9003,"Login Failed");
    }

    std::cout << "\nLogged In user - " << employee->GetName() << "(" << employee->GetRole() << ")"<< std::endl;
    std::unique_ptr<IRoleStrategy> role;

    switch(employee->GetRole()) {
        case UserRole::ManagementStaff:
            role = std::make_unique<ManagementStaffRole>();
            break;
        case UserRole::HardwareEngineer:
            role = std::make_unique<HardwareEngineerRole>();
            break;
        case UserRole::SoftwareEngineer:
            role = std::make_unique<SoftwareEngineerRole>();
            break;
    }

    return std::make_unique<EmployeeService>(employeeRepo,std::move(role),employee,logger);
}