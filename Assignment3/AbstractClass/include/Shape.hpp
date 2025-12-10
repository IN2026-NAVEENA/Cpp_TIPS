#pragma once

#include<string>

/*@brief Represent the model for Shape.*/
class Shape
{
    public:
        /*
        @brief Calculates the area of the shape.
        @return The calculated area of the shape.
        */
        virtual double CalculateArea() = 0;

        /*
        @brief Gets the name of the shape.
        @return The name of the shape.
        */
        virtual std::string_view GetShapeName() const = 0;

        /*
        @brief Virtual default destructor for Shape.
        Ensures proper cleanup of derived objects when deleted through a Shape pointer.
        */
        virtual ~Shape() = default;
};