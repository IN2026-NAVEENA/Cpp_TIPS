#include<iostream>
#define MAX_COUNT 5

/// @brief Increments count each time the funciton is called and displays the current count.
void incrementCallCount()
{
    static int count = 0;
    std::cout << "The function was called " << ++count << " time\n";
}

/// @brief Entry point of the program.
int main()
{
    for(int i = 0; i < MAX_COUNT; i++)
    {
        incrementCallCount();
    } 
    return 0; 
}