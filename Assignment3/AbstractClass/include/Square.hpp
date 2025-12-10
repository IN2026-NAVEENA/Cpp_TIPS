#pragma once

#include<string>
#include "Shape.hpp"

class Square : public Shape
{
    public:
        /*
        @brief Parameterized constructor that initializes square with side.
        @param radius The value of the side.
        */
        Square(double side) : side(side) {}

        /*
        @brief Calculates the area of the square.
        @return The calculated area of the square.
        */
        double CalculateArea() override;

        /*
        @brief Gets the name of the shape.
        @return The name of the shape.
        */
        std::string_view GetShapeName() const override;
    
    private:
        /*@brief The side of the square.*/
        double side;
};