#include "Task.hpp"
#include <sstream>
#include "DivideByZeroException.hpp"

/*
@brief Creates a task from the given operation and two operands.
@param operation The arithmetic operation to perform ("+", "-", "*", "/").
@param firstInteger The first operand of the operation.
@param secondInteger The second operand of the operation.
@return A string containing the operation and operand.
*/
std::string CreateTask(const std::string& operation, double firstInteger, double secondInteger) {
    std::ostringstream taskStream;
    taskStream << operation << " " << firstInteger << " " << secondInteger;
    return taskStream.str();
}

/*
@brief Parses a task string into task struct.
@param taskString A string containing the operation and operand.
@return A task struct with parsed operation and operand.
*/
Task ParseTask(const std::string& taskString) {
    Task task;
    std::stringstream taskStream(taskString);
    taskStream >> task.operation >> task.firstNumber >> task.secondNumber;
    return task;
}

/*
@brief Executes the arithmetic operation defined in a Task. 
@param task Contains the operation and two operands.
@return The result of the operation.
*/
double PerformOperation(const Task& task) {
    if (task.operation == "+") {
        return task.firstNumber + task.secondNumber;
    } 
    else if (task.operation == "-") {
        return task.firstNumber - task.secondNumber;
    } 
    else if (task.operation == "*") {
        return task.firstNumber * task.secondNumber;
    } 
    else {
        if (task.secondNumber == 0) {
            throw DivideByZeroException(104, "Attempt to divide by zero");
        }
        return task.firstNumber / task.secondNumber;
    }
}