#pragma once

#include<string>

/*@brief Menu-driven calculator loop.*/
void Run();

/*
@brief Performs addition operation.
@param firstInteger The first integer to be added.
@param secondInteger The second integer to be added.
@return The sum of firstInteger and secondInteger.
*/
double Add(double firstInteger, double secondInteger);

/*
@brief Performs subtraction operation.
@param firstInteger The number from which secondInteger will be subtracted.
@param secondInteger The number to subtract from firstInteger.
@return The sum of firstInteger and secondInteger.
*/
double Subtract(double firstInteger, double secondInteger);

/*
@brief Performs multiplication operation.
@param firstInteger The first integer to be multiplied.
@param secondInteger The second integer to be multiplied.
@return The product of firstInteger and secondInteger.
*/
double Multiply(double firstInteger, double secondInteger);

/*
@brief Performs division operation.
@param firstInteger The dividend.
@param secondInteger The divisor.
@return The quotient of firstInteger and secondInteger.
*/
double Divide(double firstInteger, double secondInteger);

/*
@brief Gets an integer from the user.
@param message The message displayed to the user to get input.
@return The integer entered by the user.
*/
double GetInteger(const std::string& message);

/*
@brief Gets the choice from the user to perform arithmetic operation.
@return The choice entered by the user.
*/
int GetUserChoice();