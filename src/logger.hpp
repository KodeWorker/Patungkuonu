// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef SRC_LOGGER_HPP_
#define SRC_LOGGER_HPP_
#include <string>
#include <mutex>
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace Patungkuonu {  // namespace Patungkuonu

class LogLevel {
 public:
  enum Enum{ INFO, WARNING, ERROR};

  //constexpr LogLevel() = default;
  /* implicit */ constexpr LogLevel(Enum e) : e(e) {}

  // Allows comparisons with Enum constants.
  constexpr operator Enum() const { return e; }

  // Needed to prevent if(c)
  explicit operator bool() const = delete;

  std::string to_string() {
    switch (e) {
      case INFO:
        return "INFO";
      case WARNING:
        return "WARNING";
      case ERROR:
        return "ERROR";
      default:
        return "UNKNOWN";
    }
  }

 private:
  Enum e;
};

class Logger {
 public:
  static Logger& GetInstance();
  void set_filepath(const std::string filepath);
  Logger(Logger const&) = delete;
  void operator=(Logger const&) = delete;
  void info(const std::string message, bool show = true) { log(message, LogLevel::INFO, show); }
  void warning(const std::string message, bool show = true) { log(message, LogLevel::WARNING, show); }
  void error(const std::string message, bool show = true) { log(message, LogLevel::ERROR, show); }
 private:
  std::string filepath = "log.txt";
  std::mutex mtx;
  Logger() {}
  void log(const std::string message, LogLevel level = LogLevel::INFO, bool show = true);
};

}  // namespace Patungkuonu

#endif  // SRC_LOGGER_HPP_
