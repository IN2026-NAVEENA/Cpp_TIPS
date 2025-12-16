#include "Repositories/EmployeeRepo.hpp"
#include<algorithm>

/*
@brief Generates the employee id of the new employee.
@return The new employee id.
*/
size_t EmployeeRepo::GenerateEmployeeId() {
    return ++nextId;
}

/*
@brief Authenticates an employee using their username and password.
@param name The username of the employee.
@param password The password of the employee.
@return A pointer to the authenticated Employee object if the credentials match; otherwise, returns nullptr.
*/
Employee* EmployeeRepo::Authenticate(const std::string& name, const std::string& password) {
    for(auto& employee : employees_) {
        if(employee->GetUserName() == name && employee->GetPassword() == password) {
            return employee.get();
        }
    }
    return nullptr;
};

/*
@brief Retrieves all employees stored in the repository.
@return A constant reference to the vector containing unique pointers to employee objects.
*/
const std::vector<std::unique_ptr<Employee>>& EmployeeRepo::GetAllEmployees() const {
    return employees_;
};

/*
@brief Gets the total number of employees stored in the repository.
@return The number of employees currently held in the vector.
*/
const size_t EmployeeRepo::GetEmployeeCount() const {
    return employees_.size();
}

/*
@brief Finds an employee in the repository by their id.
@param id The id of the employee.
@return A pointer to the Employee object if found; otherwise, returns nullptr.
*/
Employee* EmployeeRepo::FindEmployeeById(int id) const {
    for(auto& employee : employees_) {
        if(employee->GetId() == id) {
            return employee.get();
        }
    }
    return nullptr; 
};

/*
@brief Adds a new employee to the repository.
@param employee New employee to be added to the repository.
*/
void EmployeeRepo::AddEmployee(std::unique_ptr<Employee>&& employee) {
    employees_.emplace_back<>(std::move(employee));
};

/*
@brief Removes an employee from the repository.
@param id The id of the employee who will be removed.
@return True if the employee is removed; otherwise, returns false.
*/
bool EmployeeRepo::RemoveEmployee(int id) {
    auto employee = std::remove_if(employees_.begin(),employees_.end(), [id](const std::unique_ptr<Employee>& employee) {
        return employee->GetId() == id;
    });
    if(employee == employees_.end()) {
        return false;
    }
    employees_.erase(employee,employees_.end());
    return true;
};

/*
@brief Updates the position of the employee.
@param employee A pointer to the Employee object whose position will be updated.
@param position The new Position value to assign to the employee.
*/
void EmployeeRepo::UpdateEmployeePosition(Employee* employee, Position position) {
    employee->SetPosition(position);  
};

/*
@brief Updates the salary of the employee.
@param employee A pointer to the Employee object whose salary will be updated.
@param salary The new Position value to assign to the employee.
*/
void EmployeeRepo::UpdateEmployeeSalary(Employee* employee, double salary) {
    employee->SetSalary(salary);  
};