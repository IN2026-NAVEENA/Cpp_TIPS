#include<iostream>
#include "Signal.hpp"

std::atomic<bool> stopFlag = false;

/*
@brief Handles the SIGINT signal by stopping the logging loop.
@param sig The signal number received. 
*/
void SignalHandler(int sig)
{
    std::cout << "Data logging stopped!";
    stopFlag = true;
}

/// @brief Sets up the signal handler for SIGINT
void SetUpSignalHandler()
{
    signal(SIGINT, SignalHandler);
}