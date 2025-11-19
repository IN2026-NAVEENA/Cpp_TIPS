#include<iostream>
#include<exception>
#include "Calculator.hpp"
#include "DivideByZeroException.hpp"
#include "Validation.hpp"

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
                }
            std::cout << "\nResult: " << result << std::endl;
        }
        catch(DivideByZeroException& e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    } while (userChoice != 5);
}

double Add(double firstInteger, double secondInteger)
{
    return firstInteger + secondInteger;
}

double Subtract(double firstInteger, double secondInteger)
{
    return firstInteger - secondInteger;
}

double Multiply(double firstInteger, double secondInteger)
{
    return firstInteger * secondInteger;
}

double Divide(double firstInteger, double secondInteger)
{
    if (secondInteger == 0)
    {
        throw DivideByZeroException();
    }
    return firstInteger / secondInteger;
}

double GetInteger(std::string prompt)
{
    double integer;
    do
    {        
        std::cout << "Enter " << prompt;
        std::cin >> integer;
    } while(!isValidInteger());

    return integer;
}

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