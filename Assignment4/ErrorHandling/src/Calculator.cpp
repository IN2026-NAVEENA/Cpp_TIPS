#include<iostream>
#include<exception>
#include "Calculator.hpp"
#include "DivideByZeroException.hpp"
#include "Validation.hpp"

/// @brief Menu-driven calculator loop.
void Run()
{
    int userChoice;
    double firstInteger, secondInteger, result;

    do 
    {
        std::cout <<"\n1.Addition" << std::endl
                  <<  "2.Subtraction" << std::endl
                  <<  "3.Multiplication" << std::endl
                  <<  "4.Division" << std::endl
                  <<  "5.Exit" << std::endl;

        userChoice = GetUserChoice();

        try
        {
            if (userChoice == 5) 
            {
                std::cout << "Exiting the application!" << std::endl;
                break;
            }

            firstInteger = GetInteger("first integer: ");
            secondInteger = GetInteger("second integer: ");
            
            switch (userChoice) 
            {
                case 1: 
                    result = Add(firstInteger, secondInteger);
                    break;
                case 2: 
                    result = Subtract(firstInteger, secondInteger);
                    break;
                case 3: 
                    result = Multiply(firstInteger, secondInteger);
                    break;
                case 4: 
                    result = Divide(firstInteger, secondInteger);
                    break;
                default:
                    std::cout << "Invalid choice! Enter a number between 1-5.";
                    break;
            }
            std::cout << "\nResult: " << result << std::endl;
        }
        catch(DivideByZeroException& e)
        {
            std::cerr << "\nError " << e.ErrorCode() << " : " << e.what() << std::endl;
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

    } while (userChoice != 5);
}

/*
@brief Performs addition operation.
@param firstInteger The first integer to be added.
@param secondInteger The second integer to be added.
@return The sum of firstInteger and secondInteger.
*/
double Add(double firstInteger, double secondInteger)
{
    return firstInteger + secondInteger;
}

/*
@brief Performs subtraction operation.
@param firstInteger The number from which secondInteger will be subtracted.
@param secondInteger The number to subtract from firstInteger.
@return The sum of firstInteger and secondInteger.
*/
double Subtract(double firstInteger, double secondInteger)
{
    return firstInteger - secondInteger;
}

/*
@brief Performs multiplication operation.
@param firstInteger The first integer to be multiplied.
@param secondInteger The second integer to be multiplied.
@return The product of firstInteger and secondInteger.
*/
double Multiply(double firstInteger, double secondInteger)
{
    return firstInteger * secondInteger;
}

/*
@brief Performs division operation.
@param firstInteger The dividend.
@param secondInteger The divisor.
@return The quotient of firstInteger and secondInteger.
*/
double Divide(double firstInteger, double secondInteger)
{
    if (secondInteger == 0)
    {
        throw DivideByZeroException(104, "Attempt to divide by zero");
    }
    return firstInteger / secondInteger;
}

/*
@brief Gets an integer from the user.
@param message The message displayed to the user to get input.
@return The integer entered by the user.
*/
double GetInteger(const std::string& message)
{
    double integer;
    do
    {        
        std::cout << "Enter " << message;
        std::cin >> integer;
    } while(!isValidInteger());

    return integer;
}

/*
@brief Gets the choice from the user to perform arithmetic operation.
@return The choice entered by the user.
*/
int GetUserChoice()
{
    int userChoice;
    do
    {        
        std::cout << "Enter your choice: ";
        std::cin >> userChoice;
    } while(!isValidInteger());

    return userChoice;
}