#include "UI/LoginUI.hpp"
#include<iostream>
#include "Exceptions/EmployeeManagementException.hpp"
#include "Repositories/EmployeeRepo.hpp"
#include "Services/AuthService.hpp"
#include "UI/EmployeeManagementUI.hpp"
#include "UI/InputManager.hpp"
#include "Services/Validation.hpp"

/*
@brief Displays the login menu for the Employee Management System.
*/
void LoginMenu() {
    EmployeeRepo employeeRepo;
    Logger logger("logs");
    employeeRepo.AddEmployee(std::make_unique<Employee>(1,std::string("Naveena"),std::string("N@veena16"),UserRole::ManagementStaff,Position::Junior,5000));
    AuthService authService(employeeRepo, logger);
    int userChoice;
    do {
        std::cout << "1.Login\n2.Exit\n" << std::endl;
        userChoice = GetValidInput<size_t>("Enter your choice: ", isValidNumber);
        try {
            if(userChoice == 2) {
                std::cout << "Exiting the application\n" <<std::endl;
                break;
            } 
            else if (userChoice == 1) {
                std::string name = GetValidInput<std::string>("Enter your user name(id_name): ", isValidUserName);
                std::string password = GetValidInput<std::string>("Enter your password: ", isValidPassword);
                std::unique_ptr<EmployeeService> employeeService = authService.Login(name, password);
                EmployeeManagementMenu(employeeService.get());
            }
            else {
                std::cout << "Invalid choice\n" <<std::endl;
            }
        }
        catch(EmployeeManagementException& e) {
            std::cerr << "\nError " << e.ErrorCode() << " : " << e.what() << std::endl;
        }
    } while(userChoice != 2);
}

