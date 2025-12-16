#include "Services/EmployeeService.hpp"
#include<iostream>
#include "Services/IRoleStrategy.hpp"
#include "Exceptions/EmployeeManagementException.hpp"
#include "Services/Validation.hpp"
#include "UI/InputManager.hpp"
#include "Models/CreateEmployeeDto.hpp"
#include "Models/ManagementStaff.hpp"
#include "Models/HardwareEngineer.hpp"
#include "Models/SoftwareEngineer.hpp"

/*@brief Prompts for employee details and adds a new employee to the repository.*/
void EmployeeService::AddEmployee() {
    if(employeeRole->canAddEmployee()) {
        auto newEmployeeDto = GetEmployeeDetails();
        auto newEmployee = CreateEmployee(newEmployeeDto);
        employeeRepo.AddEmployee(std::move(newEmployee));
        std::cout << "\nNew employee added successfully\n";
        logger.Log(LogLevel::Info, "New employee added successfully");
    }
    else {
        logger.Log(LogLevel::Error, "9003-Unauthorized access attempt");
        throw EmployeeManagementException(9003,"Unauthorized access attempt");
    }
}

/*@brief Prompts for an employee ID and removes an existing employee from the repository.*/
void EmployeeService::RemoveEmployee() {
    if(employeeRole->canRemoveEmployee()) {
        size_t id = GetValidInput<size_t>("Enter employee id: ", isValidNumber);

        if(!employeeRepo.RemoveEmployee(id)) {
            logger.Log(LogLevel::Error, "9002-Employee not found");
            throw EmployeeManagementException(9002,"Employee not found");
        };
        std::cout << "\nEmployee removed successfully\n";
        logger.Log(LogLevel::Info, "Employee removed successfully");
    }
    else {
        logger.Log(LogLevel::Error, "9003-Unauthorized access attempt");
        throw EmployeeManagementException(9003,"Unauthorized access attempt");
    }
}

/*@brief Prompts for an employee ID and new position and updates the position of an existing employee.*/
void EmployeeService::UpdateEmployeePosition() {
    if(employeeRole->canUpdatePosition()) {   
        Employee* employee = FindEmployee();
        size_t positionChoice = GetValidInput<size_t>("Select new position\n"
            "1.Junior\n"
            "2.Senior\n"
            "3.Lead\n"
            "Enter position choice: ", isValidChoice);
        Position newPosition = MapChoiceToPosition(positionChoice);

        employeeRepo.UpdateEmployeePosition(employee, newPosition);
        std::cout << "\nEmployee position updated successfully\n";
        logger.Log(LogLevel::Info, "Employee position updated successfully");
    }
    else {
        logger.Log(LogLevel::Error, "9003-Unauthorized access attempt");
        throw EmployeeManagementException(9003,"Unauthorized access attempt");
    }
}

/*@brief Prompts for an employee ID and new salary and updates the salary of an existing employee.*/
void EmployeeService::UpdateEmployeeSalary() {
    if(employeeRole->canUpdateSalary()) {
        Employee* employee = FindEmployee();
        double newSalary = GetValidInput<double>("Enter new salary: ", isValidSalary);
        employeeRepo.UpdateEmployeeSalary(employee, newSalary);
        std::cout << "\nEmployee salary updated successfully\n";
        logger.Log(LogLevel::Info, "Employee salary  successfully");
    }
    else {
        logger.Log(LogLevel::Error, "9003-Unauthorized access attempt");
        throw EmployeeManagementException(9003,"Unauthorized access attempt");
    }
}

/*@brief Prompts for  new hardware unit and updates the hardware unit of an existing employee.*/
void EmployeeService::UpdateHardwareCount() {
    if(employeeRole->canUpdateHardwareCount()) {
        auto hw = dynamic_cast<HardwareEngineer*>(employee);
        size_t count = GetValidInput<size_t>("Enter hardware count: ", isValidNumber);
        hw->SetHardwareCount(count);
        std::cout << "Number of hardware count: " << hw->GetHardwareCount();
    }
    else {
        logger.Log(LogLevel::Error, "9003-Unauthorized access attempt");
        throw EmployeeManagementException(9003,"Unauthorized access attempt");
    }
}

/*@brief Displays employees filtered by category.*/
void EmployeeService::ViewEmployeeByCategory() const {
    bool found = false;
    size_t roleChoice = GetValidInput<size_t>("Select role to filter\n"
        "1.Management staff\n"
        "2.Software engineer\n"
        "3.Hardware engineer\n"
        "Enter role choice: ", isValidChoice);
    UserRole role = MapChoiceToRole(roleChoice);

    for(auto& employee : employeeRepo.GetAllEmployees()) {
        if(employee->GetRole() == role) {
            ViewEmployee(employee.get());
            found = true;
        }
    }

    if (!found) {
        logger.Log(LogLevel::Error, "9002 - Employee not found for the selected role");
        throw EmployeeManagementException(9002,"Employee not found for the selected role");
    }
};

/*@brief Displays employees filtered by position.*/
void EmployeeService::ViewEmployeeByPosition() const {
    bool found = false;
    size_t positionChoice = GetValidInput<size_t>("Select position to filter\n"
        "1.Junior\n"
        "2.Senior\n"
        "3.Lead\n"
        "Enter position choice: ", isValidChoice);
    Position position = MapChoiceToPosition(positionChoice);

    for(auto& employee : employeeRepo.GetAllEmployees()) {
        if(employee->GetPosition() == position) {
            ViewEmployee(employee.get());
            found = true;
        }
    }

    if (!found) {
        logger.Log(LogLevel::Error, "9002 - Employee not found for the selected position");
        throw EmployeeManagementException(9002,"Employee not found for the selected position");
    }
};

/*@brief Displays employees filtered by id.*/
void EmployeeService::ViewEmployeeById() const {
    Employee* employee = FindEmployee();
    ViewEmployee(employee);
};

/*@brief Displays the total count of employees.*/
void EmployeeService::ViewEmployeeCount() const {
    size_t count = employeeRepo.GetEmployeeCount();
    if(count == 0) {
        std::cout << "\nNo employee data found\n" << std::endl;
        logger.Log(LogLevel::Error, "9002-No employee data found");
    }
    else {
        std::cout << "\nNumber of employee: " << count << std::endl;
    }
};

/*@brief Displays the total hardware unit count of the employee.*/
void EmployeeService::ViewHardwareCount() const {
    if(employeeRole->canViewHardwareCount()) {
        auto hw = dynamic_cast<HardwareEngineer*>(employee);
        std::cout << "\nNumber of hardware count: " << hw->GetHardwareCount();
    }
    else {
        logger.Log(LogLevel::Error, "9003-Unauthorized access attempt");
        throw EmployeeManagementException(9003,"Unauthorized access attempt");
    }
};

/*
@brief Finds an employee by ID.
@return Pointer to the found Employee object.
*/
Employee* EmployeeService::FindEmployee() const {
    size_t id = GetValidInput<size_t>("Enter employee id: ", isValidNumber);
    Employee* employee = employeeRepo.FindEmployeeById(id);
    if (employee == nullptr) {
        logger.Log(LogLevel::Error, "9002-Employee not found");
        throw EmployeeManagementException(9002,"Employee not found");
    }
    return employee;
}

/*
@brief Displays details of the given employee.
@param employees Pointer to the employee whose details should be displayed.
*/
void EmployeeService::ViewEmployee(const Employee* employee) const {
    if(employeeRole->canViewSalary()) {
        std::cout << "\nId: " << employee->GetId() << std::endl
                      << "Name: " << employee->GetName() << std::endl
                      << "Position: " << employee->GetPosition() << std::endl
                      << "Salary: " << employee->GetSalary() << std::endl;
    }
    else {
        std::cout << "\nId: " << employee->GetId() << std::endl
                      << "Name: " << employee->GetName() << std::endl
                      << "Position: " << employee->GetPosition() << std::endl;
    }
};

/*
@brief Collects employee details from user input.
@return A CreateEmployeeDto containing the employee details.
*/
CreateEmployeeDto EmployeeService::GetEmployeeDetails() const {
    CreateEmployeeDto newEmployee;
    newEmployee.id = EmployeeRepo::GenerateEmployeeId();

    newEmployee.name = GetValidInput<std::string>("Enter employee name: ", isValidName);

    newEmployee.password = GetValidInput<std::string>("Enter password: ", isValidPassword);

    size_t roleChoice = GetValidInput<size_t>("Select new role\n1.Management staff\n2.Software engineer\n3.Hardware engineer\nEnter role choice: ", isValidChoice);
    newEmployee.role = MapChoiceToRole(roleChoice);

    size_t positionChoice = GetValidInput<size_t>("Select new position\n1.Junior\n2.Senior\n3.Lead\nEnter position choice: ", isValidChoice);
    newEmployee.position = MapChoiceToPosition(positionChoice);

    newEmployee.salary = GetValidInput<double>("Enter employee salary: ", isValidSalary);

    if(newEmployee.role == UserRole::HardwareEngineer) {
        newEmployee.hardwareCount = GetValidInput<size_t>("Enter hardware count: ", isValidNumber);
    }
    return newEmployee;
};

/*
@brief Creates a new employee instance.
@param employee Dto containing employee details.
@return A unique_ptr to the newly created Employee object.
*/
std::unique_ptr<Employee> EmployeeService::CreateEmployee(const CreateEmployeeDto& employee) {
    switch(employee.role) {
        case UserRole::ManagementStaff:
            return std::make_unique<ManagementStaff>(employee.id,employee.name,employee.password,employee.role,employee.position,employee.salary);
        case UserRole::SoftwareEngineer:
            return std::make_unique<SoftwareEngineer>(employee.id,employee.name,employee.password,employee.role,employee.position,employee.salary);
        case UserRole::HardwareEngineer:
            return std::make_unique<HardwareEngineer>(employee.id,employee.name,employee.password,employee.role,employee.position,employee.salary,employee.hardwareCount);
        default:
            return nullptr;
    }
};

/*
@brief Converts a position enum value to its string representation.
@param choice The position to convert.
@return A string representing the given position.
*/
Position EmployeeService::MapChoiceToPosition(size_t choice) const {
    switch (choice) {
        case 1: 
            return Position::Junior;
        case 2: 
            return Position::Senior;
        case 3: 
            return Position::Lead;
        default:
            throw std::invalid_argument("Invalid choice for position");
    }
};

/*
@brief Converts a user role enum value to its string representation.
@param choice The role to convert.
@return A string representing the given user role.
*/
UserRole EmployeeService::MapChoiceToRole(size_t choice) const {
    switch (choice) {
        case 1:
            return UserRole::ManagementStaff;
        case 2:
            return UserRole::SoftwareEngineer;
        case 3:
            return UserRole::HardwareEngineer;
        default:
            throw std::invalid_argument("Invalid choice for role");
    }
};