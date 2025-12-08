#include<iostream>

/// @brief Increments count each time the funciton is called and displays the current count.
void incrementCallCount()
{
    static int count = 0;
    std::cout << "The function was called " << ++count << " time" << std::endl;
}

/// @brief Entry point of the program.
int main()
{
    constexpr int maxCallCount = 5;
    for(int callCount = 1; callCount <= maxCallCount; ++callCount)
    {
        incrementCallCount();
    } 
    return 0; 
}