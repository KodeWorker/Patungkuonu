// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "setting.hpp"  // NOLINT
#include "logger.hpp"  // NOLINT

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

void Setting::Serialize(const std::string& path) const {
    // Serialize the data
    std::ofstream outFile(path, std::ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(m_window_name.c_str()), sizeof(m_name_length));
        outFile.write(reinterpret_cast<const char*>(&m_window_width), sizeof(m_window_width));
        outFile.write(reinterpret_cast<const char*>(&m_window_height), sizeof(m_window_height));
        outFile.close();
    } else {
        Logger::GetInstance().error("Failed to open file for serialization");
    }
}

void Setting::Deserialize(const std::string& path) {
    // Deserialize the data
    std::ifstream inFile(path, std::ios::binary);
    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&m_window_name[0]), sizeof(m_name_length));
        inFile.read(reinterpret_cast<char*>(&m_window_width), sizeof(m_window_width));
        inFile.read(reinterpret_cast<char*>(&m_window_height), sizeof(m_window_height));
        inFile.close();
    } else {
        Logger::GetInstance().error("Failed to open file for deserialization");
    }
}

}  // namespace Patungkuonu
