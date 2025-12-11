#pragma once

#include<string>
#include<filesystem>
#include<filesystem>
#include<fstream>
#include<vector>

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

        /*@brief Starts the logging loop until stopFlag is set.*/
        void Run();

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
        @brief Writes a log entry with a timestamp.
        @param file The output file stream to write to.
        */
        void LogEntry(std::ofstream& file);

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
