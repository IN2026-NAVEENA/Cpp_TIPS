#pragma once

#include "Repositories/EmployeeRepo.hpp"
#include "Services/EmployeeService.hpp"

class AuthService {
    public:
        /*
        @brief Constructs an authentication service with the given repository and logger.
        @param repo Reference to the EmployeeRepo used for employee authentication.
        @param log Reference to the Logger used for logging authentication events.
        */
        AuthService(EmployeeRepo& repo, Logger& log) 
            : employeeRepo(repo), logger(log){}

        /*
        @brief Authenticate an employee and create an EmployeeService.
        @param name The username of the employee trying to log in.
        @param password The password of the employee.
        @return A unique_ptr to an EmployeeService instance for the authenticated employee.
        */
        std::unique_ptr<EmployeeService> Login(const std::string& name, const std::string& password);

    private:
        /*@brief Reference to the employee repository.*/
        EmployeeRepo& employeeRepo;
        /*@brief Reference to the logger repository.*/
        Logger& logger;
};