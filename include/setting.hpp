// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_SETTING_HPP_
#define INCLUDE_SETTING_HPP_
#include <string>
#include "lib_export_options.hpp"

namespace Patungkuonu {  // namespace Patungkuonu

class Serializable {
 public:
  void Serialize(const std::string& path);
  void Deserialize(const std::string& path);
};

class LIB_EXPORT Setting : public Serializable {
 public:
  Setting();
  ~Setting();
  const std::string& GetWindowName() const;
  void SetWindowName(const std::string& window_name);
  const int& GetWindowWidth() const;
  void SetWindowWidth(int window_width);
  const int& GetWindowHeight() const;
  void SetWindowHeight(int window_height);
 private:
  std::string m_window_name{"Engine"};
  int m_window_width{800};
  int m_window_height{600};
};

}  // namespace Patungkuonu

#endif  // INCLUDE_SETTING_HPP_
