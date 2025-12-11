#pragma once

#include<utility>

/*
@brief Adds two values of type T.
@tparam T The type of the values to be added.
@param firstValue The first operand.
@param secondValue The second operand.
@return The sum of the two input values.
*/
template <typename T> 
auto AddLiterals(T&& firstValue, T&& secondValue) {
    return std::forward<T>(firstValue) + std::forward<T>(secondValue);
}