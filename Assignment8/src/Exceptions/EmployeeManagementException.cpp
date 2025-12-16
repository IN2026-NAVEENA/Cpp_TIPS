#include "Exceptions/EmployeeManagementException.hpp"

/*
@brief Returns the error code associated with the exception.
@return The integer error code.
*/
int EmployeeManagementException::ErrorCode() const noexcept {
    return errorCode_;
}

/*
@brief Returns the error message associated with the exception.
@return The error message. 
*/
const char* EmployeeManagementException::what() const noexcept {
    return errorMessage_.c_str();
}