// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include <fstream>
#include <iostream>
#include <sstream>
#include "setting.hpp"
#include "logger.hpp"

namespace Patungkuonu {  // namespace Patungkuonu

Setting::Setting() {
    // Initialize the config
}

Setting::~Setting() {
    // Clean up the config
}

const std::string& Setting::GetWindowName() const {
    return m_window_name;
}

void Setting::SetWindowName(const std::string& window_name) {
    m_window_name = window_name;
}

const int& Setting::GetWindowWidth() const {
    return m_window_width;
}

void Setting::SetWindowWidth(int window_width) {
    m_window_width = window_width;
}

const int& Setting::GetWindowHeight() const {
    return m_window_height;
}

void Setting::SetWindowHeight(int window_height) {
    m_window_height = window_height;
}

void Serializable::Serialize(const std::string& path) {
    // TODO(kodeworker): Serialize the data
}

void Serializable::Deserialize(const std::string& path) {
    // TODO(kodeworker) Deserialize the data
}

}  // namespace Patungkuonu
