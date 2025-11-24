#pragma once

#include<string>

/// @brief Represents a task with operation to be performed and the operands.
struct Task
{
    /// @brief The arithmetic operation to perform ("+", "-", "*", "/").
    std::string operation;
    /// @brief The first operand of the operation.
    double firstNumber;
    /// @brief The second operand of the operation.
    double secondNumber;
};

/*
@brief Creates a task from the given operation and two operands.
@param operation The arithmetic operation to perform ("+", "-", "*", "/").
@param firstInteger The first operand of the operation.
@param secondInteger The second operand of the operation.
@return A string containing the operation and operand.
*/
std::string CreateTask(const std::string& operation, double firstInteger, double secondInteger);

/*
@brief Parses a task string into task struct.
@param taskString A string containing the operation and operand.
@return A task struct with parsed operation and operand.
*/
Task ParseTask(const std::string& taskString);

/*
@brief Executes the arithmetic operation defined in a Task. 
@param task Contains the operation and two operands.
@return The result of the operation.
*/
double PerformOperation(const Task& task);
