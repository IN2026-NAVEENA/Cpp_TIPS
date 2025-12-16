#include "Logger/EventLog.hpp"
#include<iostream>
#include<algorithm>

/*
@brief Constructs a logger that manages log files in the specified directory.
@param path The directory path where log files will be created.
*/
Logger::Logger(const std::filesystem::path& path)
{
    directoryPath = path;
    CreateDirectory(directoryPath);
    currentFile = GetFilePath(directoryPath);
    outFile.open(currentFile);
}

/*@brief Ensures the current log file is properly closed.*/
Logger::~Logger()
{
    if(outFile.is_open())
    {
        outFile.close();
    }
}

/*
@brief Writes a log entry to the current log file and handles file rotation and folder size limits.
@param level The severity level of the log message (e.g., Info, Warning, Error).
@param message The text message to be logged.
*/
void Logger::Log(LogLevel level, const std::string& message)
{
    if(std::filesystem::file_size(currentFile) > maxFileSize)
    {
        CreateNextFile(directoryPath);
    }

    if (GetFolderSize(directoryPath) > maxFolderSize)
    {
        auto files = GetAllFiles(directoryPath);
        SortFilesByWriteTime(files);
        DeleteFiles(files);
    }

    LogEntry(outFile, level, message);
}

/*
@brief Creates the logging directory if it does not exist.
@param path The path of the directory to create.
*/
void Logger::CreateDirectory(const std::filesystem::path& path)
{
    try
    {
        if(!std::filesystem::exists(directoryPath))
        {
            std::filesystem::create_directory(directoryPath);
        }
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Filesystem error: " << e.what()
                  << "\nPath: " << e.path1() << std::endl;
    }
}

/*
@brief Creates a new file when the size of current file exceeds maxFileSize.
@param path The path of the directory to create the new log file.
*/
void Logger::CreateNextFile(const std::filesystem::path& path)
{
    outFile.close();
    currentFile = GetFilePath(path);
    outFile.open(currentFile);
}

/*
@brief Writes a log entry with a timestamp.
@param file The output file stream to write to.
*/
void Logger::LogEntry(std::ofstream& file, LogLevel level, const std::string& message)
{
    if (file.is_open())
    {
        file << "[" << MapLevelToString(level) << "] "
             << message << std::endl;
    }
    else
    {
        std::cerr << "Failed to open log file" << std::endl;
    }
}

/*
@brief Deletes up to 5 oldest files in the directory to free space.
@param path The directory containing log files.
*/
void Logger::DeleteFiles(std::vector<std::filesystem::directory_entry> files)
{
    int deletecount = 0;

    for(auto& file : files)
    {
        if(deletecount == 5) {
            break;
        } 
        std::filesystem::remove(file);
        deletecount++;
    }
}

/*
@brief Gets all the files in the given directory path.
@param path The path of the directory.
@return The vector of files in the directory.
*/
std::vector<std::filesystem::directory_entry> Logger::GetAllFiles(const std::filesystem::path& path) {
    std::vector<std::filesystem::directory_entry> files;
    for (const auto& file : std::filesystem::directory_iterator(path)) 
    {
        if (file.is_regular_file()) 
        {
            files.emplace_back(file);
        }
    }
    return files;
}

/*
@brief Sorts the files according to the write time of the file.
@param files The vector of files to be sorted.
*/
void Logger::SortFilesByWriteTime(std::vector<std::filesystem::directory_entry>& files)
{
    std::sort(files.begin(), files.end(), [](const auto& file1, const auto& file2)
    {
        return std::filesystem::last_write_time(file1) < std::filesystem::last_write_time(file2);
    });
}

/*
@brief Converts a log level enum value to its string representation.
@param level The log level to convert (e.g., Info, Warning, Error).
@return A string representing the given log level
*/
std::string Logger::MapLevelToString(LogLevel level) const
{
    switch (level) {
        case LogLevel::Info:    
            return "INFO";
        case LogLevel::Warning: 
            return "WARNING";
        case LogLevel::Error:   
            return "ERROR";
        default:                
            return "UNKNOWN";
    }
}

/*
@brief Gets the current and generates a timestamp string in the format DD-MM-YYYY_HH-MM-SS.
@return A string representing the current local time. 
*/
std::string Logger::TimeStamp()
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
std::filesystem::path Logger::GetFilePath(const std::filesystem::path& directoryPath)
{
    return directoryPath/("log_" + TimeStamp() + ".txt");
}

/*
@brief Calculates the total size of the folder.
@param directoryPath The directory whose size will be calculated.
@return The total size of files in bytes.
*/
uintmax_t Logger::GetFolderSize(const std::filesystem::path& directoryPath)
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