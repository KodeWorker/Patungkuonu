#include "logger.hpp"

Logger& Logger::GetInstance() {
    static Logger instance;
    return instance;
}

void Logger::set_filepath(const std::string filepath) {
    this->filepath = filepath;
}

std::string get_current_time() {
    std::time_t now = std::time(nullptr);
    std::tm localTime;

    #if defined(_WIN32) || defined(_WIN64)
        localtime_s(&localTime, &now); // Use localtime_s on Windows
    #else
        localtime_r(&now, &localTime); // Use localtime_r on POSIX systems
    #endif

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Logger::log(const std::string message, bool show) {
    std::lock_guard<std::mutex> lock(mtx);

    std::ofstream out_file(filepath, std::ios::app);
    std::string out = "[" + get_current_time() + "] " + message;

    if(show)
        std::cout << out << std::endl;

    if(out_file.is_open())
    {
        out_file << out << std::endl;
        out_file.close();
    }
}