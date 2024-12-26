// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include "setting.hpp"
#include "engine.hpp"

int main() {
    Patungkuonu::Setting setting;
    setting.SetWindowName("Demo");
    setting.SetWindowWidth(1024);
    setting.SetWindowHeight(768);

    Patungkuonu::Engine engine(setting);
    engine.run();

    return 0;
}
