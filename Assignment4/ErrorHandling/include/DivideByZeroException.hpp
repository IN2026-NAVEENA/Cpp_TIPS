#pragma once

#include<exception>
#include<string>

class DivideByZeroException : std::exception
{
    private:
        /// @brief The error message associated with the exception.
        int errorCode_;

        /// @brief The error message explaining the cause of the exception.
        std::string errorMessage_;

    public:
        /*
        @brief Constructs a DivideByZeroException with an error code and message.
        @param code The integer error code.
        @param message The error message explaining the cause of the exception.
        */
        DivideByZeroException(int code, const std::string& message);

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
};