#pragma once

#include<cmath>
#include<string>
#include "Shape.hpp"

constexpr double PI = 3.14159265358979323846;

class Circle : public Shape
{
    public:
        /*
        @brief Parameterized constructor that initializes circle with radius.
        @param radius The value of the radius.
        */
        Circle(double radius) : radius(radius){}

        /*
        @brief Calculates the area of the circle.
        @return The calculated area of the circle.
        */
        double CalculateArea() override;

        /*
        @brief Gets the name of the shape.
        @return The name of the shape.
        */
        std::string_view GetShapeName() const override;

    private:
        /*@brief The radius of the circle.*/
        double radius;
};