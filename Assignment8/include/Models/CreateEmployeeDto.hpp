#pragma once

#include<string>
#include "Enums/Position.hpp"
#include "Enums/UserRole.hpp"

/*@brief DTO used for creating a new employee.*/
struct CreateEmployeeDto {
    int id;
    std::string name;
    std::string password;
    UserRole role;
    Position position;
    double salary;
    int hardwareCount = 0;
};