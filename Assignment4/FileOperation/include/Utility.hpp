#pragma once

#include<string>
#include<filesystem>

/*
@brief Gets the current and generates a timestamp string in the format DD-MM-YYYY_HH-MM-SS.
@return A string representing the current local time. 
*/
std::string TimeStamp();

/*
@brief Generates a new file path with timestamp based filename.
@param directoryPath The directory where the log file will be created.
@return The filepath for new log file.
*/
std::filesystem::path GetFilePath(const std::filesystem::path& directoryPath);

/*
@brief Calculates the total size of the folder.
@param directoryPath The directory whose size will be calculated.
@return The total size of files in bytes.
*/
uintmax_t GetFolderSize(const std::filesystem::path& directoryPath);