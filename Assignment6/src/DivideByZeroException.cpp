#include "DivideByZeroException.hpp"

/*
@brief Constructs a DivideByZeroException with an error code and message.
@param code The integer error code.
@param message The error message explaining the cause of the exception.
*/
DivideByZeroException::DivideByZeroException(int code, const std::string& message) : errorCode_(code), errorMessage_(message){}

/*
@brief Returns the error message associated with the exception.
@return The error message. 
*/
const char* DivideByZeroException::what() const noexcept
{
    return errorMessage_.c_str();
}

/*
@brief Returns the error code associated with the exception.
@return The integer error code.
*/
int DivideByZeroException::ErrorCode() const noexcept 
{
    return errorCode_;
}