#include<iostream>
extern "C" {
#include "Factorial.h"
}

/*@brief Entry point of the program.*/
int main() {
    std::cout << "The factorial of 5 is: " << Factorial(5) << std::endl;
    return 0;
}