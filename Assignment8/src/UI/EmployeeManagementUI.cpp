#include "UI/EmployeeManagementUI.hpp"
#include<iostream>
#include<memory>
#include "Services/EmployeeService.hpp"
#include "Exceptions/EmployeeManagementException.hpp"
#include "UI/InputManager.hpp"
#include "Services/Validation.hpp"

/*
@brief Displays the Employee Management Menu and handles user interactions.
@param employeeService Pointer to an EmployeeService instance used to perform employee-related operations.
*/
void EmployeeManagementMenu(EmployeeService* employeeService) {
    int userChoice;
    do {
        std::cout << "\n1.Add employee\n"
                        "2.Remove employee\n"
                        "3.Update Employee Position\n"
                        "4.Update Employee Salary\n"
                        "5.Update Hardware units\n"
                        "6.View Employee by category\n"
                        "7.View Employee by position\n"
                        "8.View number of employee\n"
                        "9.View Hardware units\n"
                        "10.Search Employee by id\n"
                        "11.Logout\n" << std::endl;
        userChoice = GetValidInput<size_t>("Enter your choice: ", isValidNumber);
        try{

            if(userChoice == 11) {
                std::cout << "Logged out!\n" <<std::endl;
                break;
            }
            else {
                switch(userChoice) {
                    case 1:
                        employeeService->AddEmployee();
                        break;
                    case 2:
                        employeeService->RemoveEmployee();
                        break;
                    case 3:
                        employeeService->UpdateEmployeePosition();
                        break;
                    case 4:
                        employeeService->UpdateEmployeeSalary();
                        break;
                    case 5:
                        employeeService->UpdateHardwareCount();
                        break;
                    case 6:
                        employeeService->ViewEmployeeByCategory();
                        break;
                    case 7:
                        employeeService->ViewEmployeeByPosition();
                        break;
                    case 8:
                        employeeService->ViewEmployeeCount();
                        break;
                    case 9:
                        employeeService->ViewHardwareCount();
                        break;
                    case 10:
                        employeeService->ViewEmployeeById();
                        break;
                    default:
                        std::cout << "Invalid choice!" << std::endl;
                        break;
                }
            }
        }
        catch (EmployeeManagementException& e) {
            std::cerr << "\nError " << e.ErrorCode() << " : " << e.what() << std::endl;
        }
    } while(userChoice != 11);
};