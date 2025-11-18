#include<string>
#include "Circle.hpp"

/// @brief Calculates the area of the circle.
/// @return The calculated area of the circle.
double Circle::CalculateArea()
{  
    constexpr double PI = 3.14159265358979323846;
    return 2 * PI * radius;
}

/// @brief Gets the name of the shape.
/// @return The name of the shape.
std::string Circle::GetShapeName() const
{
    return "Circle";
}