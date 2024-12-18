#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <string>
#include <mutex>
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

class Logger {
    public:
        static Logger& GetInstance();
        void set_filepath(const std::string filepath);
        void log(const std::string message, bool show = true);
        
        Logger(Logger const&) = delete;
        void operator=(Logger const&) = delete;

    private:        
        std::string filepath = "log.txt";
        std::mutex mtx; 
        Logger() {};
};

#endif // LOGGER_HPP