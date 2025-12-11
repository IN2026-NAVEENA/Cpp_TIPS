#include "Circle.hpp"
#include<string>

/*
@brief Calculates the area of the circle.
@return The calculated area of the circle.
*/
double Circle::CalculateArea()
{  
    return 2 * PI * radius;
}

/*
@brief Gets the name of the shape.
@return The name of the shape.
*/
std::string_view Circle::GetShapeName() const
{
    return "Circle";
}