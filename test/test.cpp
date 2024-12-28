// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "engine.hpp"  // NOLINT
#include "logger.hpp"  // NOLINT
#include "setting.hpp"  // NOLINT

TEST(SourceElementTest, LoggerGetInstanceTest) {
    Patungkuonu::Logger& logger = Patungkuonu::Logger::GetInstance();
}

TEST(SourceElementTest, EngineTest) {
    Patungkuonu::Setting setting;
    Patungkuonu::Engine engine(setting);
}
