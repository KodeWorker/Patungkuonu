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

namespace HPP {

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
  Logger() {}
};

}  // namespace HPP

#endif  // SRC_LOGGER_HPP_
