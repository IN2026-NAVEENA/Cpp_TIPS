#pragma once

#include<string>

/*
@brief Prompts the user for input and validates it using the provided validator.
@tparam T The type of the input value.
@tparam Validator To validate the input.
@param prompt The message displayed to the user before input.
@param validator The validation function that takes the input value and returns true if valid.
@return The validated input value of type T.
*/
template <typename T, typename Validator>
T GetValidInput(const std::string& prompt, const Validator& validator) {
    T value;
    do {
        std::cout << prompt;
        std::cin >> value;
    } while(!validator(value));
    return value;
}
