#include "Services/Validation.hpp"
#include<iostream>
#include<cmath>
#include<regex>

/*@brief Clears the input stream after a failed extraction.*/
void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
@brief Validates if the user input is a integer.
@param number The input value to validate.
@return true if input is a integer else false.
*/
bool isValidNumber(size_t number) {
    if (std::cin.fail()) {
        std::cout << "Invalid input! Not a valid integer." << std::endl;
        clearInputStream();
        return false;
    }
    return true;
}


/*
@brief Validates if the user input is a integer.
@param salary The input value to validate.
@return true if input is a integer else false.
*/
bool isValidSalary(double salary) {
    if (std::cin.fail()) {
        std::cout << "Invalid input! Not a valid salary." << std::endl;
        clearInputStream();
        return false;
    }
    else if(salary < 0) {
        std::cout << "Invalid input! Salary cannot be negative." << std::endl;
        return false;
    }
    else if(salary == 0) {
        std::cout << "Invalid input! Salary cannot be zero." << std::endl;
        return false;
    }
    return true;
}


/*
@brief Validates if the user input is a integer.
@param name The input value to validate.
@return true if input is a integer else false.
*/
bool isValidName(const std::string& name) {
    std::regex pattern("^[A-Za-z]+$");
    if(!std::regex_match(name,pattern)) {
        std::cout << "Invalid input! Name cannot have number or special character." << std::endl;
        return false;
    }
    return true;
}

/*
@brief Validates if the user input is a integer.
@param name The input value to validate.
@return true if input is a integer else false.
*/
bool isValidUserName(const std::string& name) {
    std::regex pattern("^[0-9]+_[A-Za-z]+$");
    if(!std::regex_match(name,pattern)) {
        std::cout << "Invalid user name! User name should be 'id_name'" << std::endl;
        return false;
    }
    return true;
}

/*
@brief Validates if the user input is a integer.
@param password The input value to validate.
@return true if input is a integer else false.
*/
bool isValidPassword(const std::string& password) {
    if (password.length() < 8) {
        std::cout << "Password must be at least 8 characters long.\n";
        return false;
    }
    else if (!std::regex_search(password, std::regex("[a-z]"))) {
        std::cout << "Error: Password must contain at least one lowercase letter.\n";
        return false;
    }
    else if (!std::regex_search(password, std::regex("[A-Z]"))) {
        std::cout << "Password must contain at least one uppercase letter.\n";
        return false;
    }
    else if (!std::regex_search(password, std::regex("[0-9]"))) {
        std::cout << "Password must contain at least one digit.\n";
        return false;
    }
    else if (!std::regex_search(password, std::regex("[@$!%*?&]"))) {
        std::cout << "Password must contain at least one special character (@$!%*?&).\n";
        return false;
    }
    return true;
}

/*
@brief Validates if the user input is a integer.
@param choice The input value to validate.
@return true if input is a integer else false.
*/
bool isValidChoice(size_t choice) {
    return choice >= 1 && choice <= 3;
}