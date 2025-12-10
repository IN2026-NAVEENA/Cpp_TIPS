#include "Square.hpp"
#include<string>

/*
@brief Calculates the area of the square.
@return The calculated area of the square.
*/
double Square::CalculateArea()
{
    return side * side;
} 

/*
@brief Gets the name of the shape.
@return The name of the shape.
*/
std::string_view Square::GetShapeName() const
{
    return "Square";
}