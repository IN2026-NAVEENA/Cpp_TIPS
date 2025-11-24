#pragma once

#include <string>
#include<semaphore>
#include<queue>

/// @brief Controls when the producer should get task from the user.
extern std::binary_semaphore signalToProducer;

/// @brief Controls when the consumer should perform the task and display the result.
extern std::binary_semaphore signalToConsumer;

/// @brief A queue to store the task to be performed.
extern std::queue<std::string> taskQueue;

/*
@brief Prompts the user to enter an arithmetic operation or stop.
@return A string containing the operation entered by the user.
*/
std::string GetUserOperation();

/*
@brief Prompts the user for input and validates that it is a numeric value.
@param prompt A message displayed to the user before input is requested.
@return A double value entered by the user.
*/
double GetInteger(const std::string& prompt);

/// @brief Continuously produces tasks based on user input and enqueues.
void Producer();

/// @brief Continuously performs tasks based on user input and displays the result.
void Consumer();