// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include <iostream>
#include "setting.hpp"
#include "engine.hpp"

int main() {
    Patungkuonu::Setting setting;
    setting.SetWindowName("Demo");
    setting.SetWindowWidth(1024);
    setting.SetWindowHeight(768);
    setting.Serialize("config.bin");

    Patungkuonu::Setting setting2;
    setting2.Deserialize("config.bin");

    Patungkuonu::Engine engine(setting2);
    engine.run();

    return 0;
}
