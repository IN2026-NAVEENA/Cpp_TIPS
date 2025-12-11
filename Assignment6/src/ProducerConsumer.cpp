#include "ProducerConsumer.hpp"
#include <iostream>
#include <thread>
#include <sstream>
#include "DivideByZeroException.hpp"
#include "Task.hpp"

/*@brief Controls when the producer should get task from the user.*/
std::binary_semaphore signalToProducer{1};

/*@brief Controls when the consumer should perform the task and display the result.*/
std::binary_semaphore signalToConsumer{0};

/*@brief A queue to store the task to be performed.*/
std::queue<std::string> taskQueue;

/*
@brief Prompts the user to enter an arithmetic operation or stop.
@return A string containing the operation entered by the user.
*/
std::string GetUserOperation() {
    while (true) {
        std::cout << "Enter an operation (+, -, *, /) or 'stop' to exit: ";
        std::string operation;
        std::cin >> operation;

        if (operation == "stop" || operation == "+" || operation == "-" || operation == "*" || operation == "/") {
            return operation;
        }
        std::cout << "Invalid operation!" << std::endl;
    }
}

/*
@brief Prompts the user for input and validates that it is a numeric value.
@param prompt A message displayed to the user before input is requested.
@return A double value entered by the user.
*/
double GetInteger(const std::string& prompt) {
    double integer;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::cin >> input;

        std::stringstream inputStream(input);
        if (inputStream >> integer && inputStream.eof()) {
            return integer;
        }
        std::cout << "Invalid integer!" << std::endl;
    }
}

/*@brief Continuously produces tasks based on user input and enqueues.*/
void Producer() {
    while (true) {
        signalToProducer.acquire();
        auto operation = GetUserOperation();

        if (operation == "stop") {
            taskQueue.push(operation);
            signalToConsumer.release();
            break;
        }

        double firstInteger = GetInteger("Enter first integer: ");
        double secondInteger = GetInteger("Enter second integer: ");
        taskQueue.push(CreateTask(operation, firstInteger, secondInteger));
        signalToConsumer.release();
    }
}

/*@brief Continuously performs tasks based on user input and displays the result.*/
void Consumer() {
    while (true) {
        signalToConsumer.acquire();
        std::string taskString = taskQueue.front();
        taskQueue.pop();
        Task task = ParseTask(taskString);

        if (task.operation == "stop") {
            std::cout << "Exiting the application" << std::endl;
            break;
        } 
        else {
            try {
                double result = PerformOperation(task);
                std::cout << "Result: " << task.firstNumber << task.operation
                          << task.secondNumber << " = " << result << std::endl;
            } catch (DivideByZeroException& e) {
                std::cerr << "Error " << e.ErrorCode() << " : " << e.what() << std::endl;
            }
        }
        signalToProducer.release();
    }
}