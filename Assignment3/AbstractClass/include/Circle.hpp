#pragma once
#include<cmath>
#include<string>
#include "Shape.hpp"
class Circle : public Shape
{
    private:
        /// @brief The radius of the circle.
        double radius;
    public:
        /// @brief Parameterized constructor that initializes circle with radius.
        /// @param radius The value of the radius.
        Circle(double radius) : radius(radius){}

        /// @brief Calculates the area of the circle.
        /// @return The calculated area of the circle.
        double CalculateArea() override;

        /// @brief Gets the name of the shape.
        /// @return The name of the shape.
        std::string GetShapeName() const override;
};