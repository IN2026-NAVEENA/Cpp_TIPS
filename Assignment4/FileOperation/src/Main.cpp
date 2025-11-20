#include "Logger.hpp"
#include "Signal.hpp"

/// @brief Entry point of the program. 
int main()
{
    SetUpSignalHandler();
    Logger logger("logs");
    logger.Run();
    return 0;
}