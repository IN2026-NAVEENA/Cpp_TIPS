#include "Utility.hpp"
#include<sstream>

/*
@brief Gets the current and generates a timestamp string in the format DD-MM-YYYY_HH-MM-SS.
@return A string representing the current local time. 
*/
std::string TimeStamp()
{
    std::stringstream currentTime;
    time_t now = time(0);
    tm* timeDate = localtime(&now);
    currentTime << timeDate->tm_mday << "-"
        << 1 + timeDate->tm_mon << "-"
        << 1900 + timeDate->tm_year << "_"
        << timeDate->tm_hour << "-"
        << timeDate->tm_min << "-"
        << timeDate->tm_sec;

    return currentTime.str();
}

/*
@brief Generates a new file path with timestamp based filename.
@param directoryPath The directory where the log file will be created.
@return The filepath for new log file.
*/
std::filesystem::path GetFilePath(const std::filesystem::path& directoryPath)
{
    return directoryPath/("log_" + TimeStamp() + ".txt");
}

/*
@brief Calculates the total size of the folder.
@param directoryPath The directory whose size will be calculated.
@return The total size of files in bytes.
*/
uintmax_t GetFolderSize(const std::filesystem::path& directoryPath)
{
    uintmax_t folderSize = 0;
    for (const auto& file : std::filesystem::directory_iterator(directoryPath)) 
    {
        if(file.is_regular_file())
        {
            folderSize += std::filesystem::file_size(file);
        }
    }
    return folderSize;
}