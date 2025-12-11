#include "Logger.hpp"
#include<iostream>
#include<algorithm>
#include<thread>
#include<chrono>
#include<exception>
#include "Utility.hpp"
#include "Signal.hpp"

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

/*@brief Starts the logging loop until stopFlag is set.*/
void Logger::Run(){
    std::cout << "Data logging started!\n" << "Press Ctrl+C to stop." << std::endl;

    while(!stopFlag)
    {
        LogEntry(outFile);

        if(std::filesystem::file_size(currentFile) > maxFileSize)
        {
            CreateNextFile(directoryPath);
        }

        if(GetFolderSize(directoryPath) > maxFolderSize)
        {
            auto files = GetAllFiles(directoryPath);
            SortFilesByWriteTime(files);
            DeleteFiles(files);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
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
void Logger::LogEntry(std::ofstream& file)
{
    if (file.is_open()) 
    {
        file << "Data was logged at: "<< TimeStamp() << std::endl;
    }
    else 
    {
        std::cerr << "Failed to open file: " << std::endl;
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
