#include "DivideByZeroException.hpp"

const char* DivideByZeroException::what() const noexcept
{
    return "Exception: Attempt to divide by zero.";
}