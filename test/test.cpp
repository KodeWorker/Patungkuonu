// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "engine.hpp"
#include "logger.hpp"

TEST(SourceElementTest, LoggerGetInstanceTest) {
    Patungkuonu::Logger& logger = Patungkuonu::Logger::GetInstance();
}

TEST(SourceElementTest, EngineTest) {
    Patungkuonu::Engine engine;
}
