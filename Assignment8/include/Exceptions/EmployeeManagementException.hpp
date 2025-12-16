#pragma once

#include<exception>
#include<string>

class EmployeeManagementException : std::exception {

    public:
        /*
        @brief Constructs a EmployeeManagementException with an error code and message.
        @param code The integer error code.
        @param message The error message explaining the cause of the exception.
        */
        EmployeeManagementException(int code, const std::string& message) 
            : errorCode_(code), errorMessage_(message) {}

        /*
        @brief Returns the error message associated with the exception.
        @return The error message. 
        */
        const char* what() const noexcept override;

        /*
        @brief Returns the error code associated with the exception.
        @return The integer error code.
        */
        int ErrorCode() const noexcept;
    
    private:
        /*@brief The error message associated with the exception.*/
        int errorCode_;
        /*@brief The error message explaining the cause of the exception.*/
        std::string errorMessage_;
};