#include<fstream>
#include<filesystem>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

/*
@brief Converts each character of the string to lower case.
@param word The string representing the word.
*/
void toLowerCase(std::string& word) 
{
    for(std::size_t index = 0; index < word.size(); index++) 
    {
        word[index] = tolower(word[index]);
    }
}

/*
@brief Sorts the vector of word and frequency in descending order based on frequency.
@param wordList The vector representing the word and frequency.
*/
void sortByFrequency(std::vector<std::pair<std::string, int>>& wordList)
{
    std::sort(wordList.begin(), wordList.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });
}

/*
@brief Sorts the vector of word and frequency in alphabetically.
@param wordList The vector representing the word and frequency.
*/
void sortAlphabetically(std::vector<std::pair<std::string, int>>& wordList) 
{
    std::sort(wordList.begin(), wordList.end(), [](auto& a, auto& b) {
        return a.first < b.first;
    });
}

/*
@brief Reads the word from the file path and counts the frequency of the word using unordered map.
@param filePath The path of the file to read from.
@return Unordered map containing the word and its corresponding frequency.
*/
std::unordered_map<std::string, int> readFileAndCountWords(const std::string& filePath) 
{
    std::ifstream inputFile(filePath);
    if (!inputFile) 
    {
        std::cerr << "Could not open file!" << std::endl;
    }

    std::unordered_map<std::string, int> wordCounter;
    std::string word;

    while (inputFile >> word) 
    {
        toLowerCase(word);
        ++wordCounter[word];
    }

    return wordCounter;
}

/*
@brief Displays the top 10 most frequent words in alphabetical order.
@param words The vector representing the word and frequency.
*/
void printWords(const std::vector<std::pair<std::string, int>>& words) {
    std::cout << "Top 10 words (alphabetical):\n";
    for (const auto& entry : words) {
        std::cout << entry.first << " : " << entry.second << '\n';
    }
}

/// @brief Entry point of the program.
int main()
{
    std::filesystem::path currentPath = std::filesystem::current_path();

    std::filesystem::path filePath = currentPath / "File.txt";

    std::cout << "Looking for file at: " << filePath << std::endl;

    auto wordCounter = readFileAndCountWords(filePath.string());

    std::vector<std::pair<std::string, int>> wordList(wordCounter.begin(), wordCounter.end());

    sortByFrequency(wordList);
    if (wordList.size() > 10) {
        wordList.resize(10);
    }

    sortAlphabetically(wordList);
    printWords(wordList);

    return 0;
}