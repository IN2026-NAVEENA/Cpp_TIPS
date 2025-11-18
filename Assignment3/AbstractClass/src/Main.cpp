#include<iostream>
#include "Circle.hpp"
#include "Square.hpp"

/// @brief Entry point of the program. 
int main()
{
    Shape * shapes[] = 
    {
        new Circle(4),
        new Square(10),
    };

    for (Shape * shape: shapes) 
    {
        std::cout << "The area of " << shape -> GetShapeName() << " is " << shape -> CalculateArea() << std::endl;
    }
    
    for (Shape * shape: shapes) {
        delete shape;
    }

    return 0;
}