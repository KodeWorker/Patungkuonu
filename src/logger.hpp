// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef SRC_LOGGER_HPP_
#define SRC_LOGGER_HPP_
#include <string>
#include <string_view>
#include <stdexcept>
#include <array>
#include <mutex>

namespace Patungkuonu {  // namespace Patungkuonu

class LogLevel {
 public:
  enum Enum{ INFO, WARNING, ERROR};

  // Default constructor.
  constexpr LogLevel() : e(INFO) {}
  /* implicit */ constexpr LogLevel(Enum e) : e(e) {}  // NOLINT

  // Allows comparisons with Enum constants.
  constexpr operator Enum() const { return e; }

  // Needed to prevent if(c)
  explicit operator bool() const = delete;

  constexpr std::string_view to_string() const {
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

  static constexpr std::array<LogLevel, 3> values() {
    return { LogLevel::INFO, LogLevel::WARNING, LogLevel::ERROR };
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
