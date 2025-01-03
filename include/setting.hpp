// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#pragma warning(disable: 4251)
#ifndef INCLUDE_SETTING_HPP_
#define INCLUDE_SETTING_HPP_
#include <string>
#include "lib_export_options.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

class Serializable {
 public:
  virtual void Serialize(const std::string& path) const = 0;
  virtual void Deserialize(const std::string& path) = 0;
};

class LIB_EXPORT Setting : public Serializable {
 public:
  Setting();
  ~Setting();
  void Serialize(const std::string& path) const override;
  void Deserialize(const std::string& path) override;
  // Setters and Getters
  const std::string& GetWindowName() const;
  void SetWindowName(const std::string& window_name);
  const int& GetWindowWidth() const;
  void SetWindowWidth(int window_width);
  const int& GetWindowHeight() const;
  void SetWindowHeight(int window_height);
  const std::string& GetLogPath() const;
  void SetLogPath(const std::string& log_path);
  const int& GetFrameRate() const;
  void SetFrameRate(int frame_rate);

 private:
  size_t m_name_length{32};
  std::string m_window_name{"Engine"};
  std::string m_log_path{"log.txt"};
  int m_window_width{800};
  int m_window_height{600};
  int m_frame_rate{60};
};

}  // namespace Patungkuonu

#endif  // INCLUDE_SETTING_HPP_
