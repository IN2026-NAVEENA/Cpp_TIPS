#pragma once

#include<string>

/*@brief Clears the input stream after a failed extraction.*/
void clearInputStream();

/*
@brief Validates if the user input is a integer.
@param number The input value to validate.
@return true if input is a integer else false.
*/
bool isValidNumber(size_t number);

/*
@brief Validates if the user input is a integer.
@param salary The input value to validate.
@return true if input is a integer else false.
*/
bool isValidSalary(double salary);

/*
@brief Validates if the user input is a integer.
@param name The input value to validate.
@return true if input is a integer else false.
*/
bool isValidName(const std::string& name);

/*
@brief Validates if the user input is a integer.
@param name The input value to validate.
@return true if input is a integer else false.
*/
bool isValidUserName(const std::string& name);

/*
@brief Validates if the user input is a integer.
@param password The input value to validate.
@return true if input is a integer else false.
*/
bool isValidPassword(const std::string& password);

/*
@brief Validates if the user input is a integer.
@param choice The input value to validate.
@return true if input is a integer else false.
*/
bool isValidChoice(size_t choice);