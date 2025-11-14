#pragma once
#include<string>

/// @brief Validates if the user input is positive number.
/// @param number Number to be validated.
/// @return true if input is a positive number else false.
bool isValidNumber(int number);

/// @brief Validates if the user input is name with alphabets.
/// @param name Name to be validated.
/// @return true if valid name else false.
bool isValidName(const std::string& name);