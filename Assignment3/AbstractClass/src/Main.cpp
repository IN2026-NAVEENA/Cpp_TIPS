#include<iostream>
#include<memory>
#include<vector>
#include "Circle.hpp"
#include "Square.hpp"

/*@brief Entry point of the program.*/
int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Circle>(4));
    shapes.emplace_back(std::make_unique<Square>(10));

    for (const auto& shape : shapes) {
        std::cout << "The area of " << shape->GetShapeName()
                  << " is " << shape->CalculateArea() << '\n';
    }

    return 0;
}