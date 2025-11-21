#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<exception>

/*
@brief Parses the user input into double.
@param userInput The user entered input.
@return Parsed value of the user input.
*/
double ParseToDouble(const std::string& userInput) {
    std::stringstream ss(userInput);
    double parsedValue = 0;
    if (ss >> parsedValue) {
        return parsedValue;
    } else {
        throw std::invalid_argument("Invalid input! Not a valid number");
    }
}

/*
@brief Adds a new parsed value to the set of numbers.
@param numbers Representing the vector of numbers.
@param parsedValue The value to be inserted in the set.
*/
void AddNumberToSet(std::unordered_set<double>& numbers, double parsedValue) {
    auto result = numbers.insert(parsedValue);
    if (!result.second) {
        std::cout << "Number already exist\n";
    }
}

/*
@brief Sorts the number in ascending order.
@param numbers Representing the vector of numbers.
*/
void SortNumber(std::vector<double>& numbers) {
    std::sort(numbers.begin(), numbers.end());
}

/*
@brief Displays the sorted order of the numbers entered by the user.
@param numbers Representing the vector of numbers.
*/
void DisplayNumbers(const std::vector<double>& numbers) {
    std::cout << "Sorted inputs: ";
    for(auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

/// @brief Entry point of the program.
int main() {

    std::unordered_set<double> numbers;
    std::string userInput;
    double parsedValue;

    while(true) {
        std::cout << "Enter a number (or 'exit' to finish): ";
        std::cin >> userInput;
        if(userInput == "exit") {
            break;
        }
        try {               
            parsedValue = ParseToDouble(userInput);
            AddNumberToSet(numbers, parsedValue);
        }
        catch(const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::vector<double> sortedNumbers(numbers.begin(), numbers.end());

    SortNumber(sortedNumbers);
    DisplayNumbers(sortedNumbers);

    return 0;
}