#pragma once

#include<atomic>

extern std::atomic<bool> stopFlag;

/*
@brief Handles the SIGINT signal by stopping the logging loop.
@param sig The signal number received. 
*/
void SetUpSignalHandler();

/*@brief Sets up the signal handler for SIGINT*/
void SignalHandler(int sig);
