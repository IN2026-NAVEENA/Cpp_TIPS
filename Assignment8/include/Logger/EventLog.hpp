#pragma once

#include<string>
#include<filesystem>
#include<filesystem>
#include<fstream>
#include<vector>
#include "Enums/LogLevel.hpp"

constexpr std::uintmax_t maxFolderSize = 20ull * 1024;
constexpr std::uintmax_t maxFileSize = 2ull * 1024;

class Logger{
    public:
        /*
        @brief Constructs a logger that manages log files in the specified directory.
        @param path The directory path where log files will be created.
        */
        Logger(const std::filesystem::path& directoryPath);

        /*@brief Ensures the current log file is properly closed.*/
        ~Logger();

        /*
        @brief Writes a log entry to the current log file and handles file rotation and folder size limits.
        @param level The severity level of the log message (e.g., Info, Warning, Error).
        @param message The text message to be logged.
        */
        void Log(LogLevel level, const std::string& message);

    private:
        /*@brief The path of the directory to manage lof files.*/
        std::filesystem::path directoryPath;

        /*@brief The path of the current file to create and write to.*/
        std::filesystem::path currentFile;

        /*@brief The output file stream to write to.*/
        std::ofstream outFile;

        /*
        @brief Creates the logging directory if it does not exist.
        @param path The path of the directory to create.
        */
        void CreateDirectory(const std::filesystem::path& path);

        /*
        @brief Creates a new file when the size of current file exceeds maxFileSize.
        @param path The path of the directory to create the new log file.
        */
        void CreateNextFile(const std::filesystem::path& path);

        /*
        @brief Converts a log level enum value to its string representation.
        @param level The log level to convert (e.g., Info, Warning, Error).
        @return A string representing the given log level
        */
        std::string MapLevelToString(LogLevel level) const;

        /*
        @brief Generates a new file path with timestamp based filename.
        @param directoryPath The directory where the log file will be created.
        @return The filepath for new log file.
        */
        std::filesystem::path GetFilePath(const std::filesystem::path& directoryPath);

        /*
        @brief Gets the current and generates a timestamp string in the format DD-MM-YYYY_HH-MM-SS.
        @return A string representing the current local time. 
        */
        std::string TimeStamp();

        /*
        @brief Calculates the total size of the folder.
        @param directoryPath The directory whose size will be calculated.
        @return The total size of files in bytes.
        */
        uintmax_t GetFolderSize(const std::filesystem::path& directoryPath);

        /*
        @brief Writes a log entry with a timestamp.
        @param file The output file stream to write to.
        */
        void LogEntry(std::ofstream& file, LogLevel level, const std::string& message);

        /*
        @brief Deletes up to 5 oldest files in the directory to free space.
        @param files The vector of files to be deleted.
        */
        void DeleteFiles(std::vector<std::filesystem::directory_entry> files);

        /*
        @brief Sorts the files according to the write time of the file.
        @param files The vector of files to be sorted.
        */
        void SortFilesByWriteTime(std::vector<std::filesystem::directory_entry>& files);

        /*
        @brief Gets all the files in the given directory path.
        @param path The path of the directory.
        @return The vector of files in the directory.
        */
        std::vector<std::filesystem::directory_entry> GetAllFiles(const std::filesystem::path& path);
};