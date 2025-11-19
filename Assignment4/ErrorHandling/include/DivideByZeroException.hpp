#pragma once

#include<exception>

class DivideByZeroException : std::exception
{
    public:
        const char* what() const noexcept override;
};