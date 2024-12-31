// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include "setting.hpp"  // NOLINT
#include "engine.hpp"  // NOLINT
#include "sprite.hpp"  // NOLINT

int main(int argc, char* argv[]) {
    Patungkuonu::Setting setting;
    setting.SetWindowName("Demo");
    setting.SetWindowWidth(1024);
    setting.SetWindowHeight(768);

    Patungkuonu::Sprite sprite;
    sprite.SetPath("../assets/Cute_Fantasy_Free/Player/Player.png");
    sprite.SetName("Player");
    sprite.SetSize(Patungkuonu::Size{32, 32});
    sprite.SetPosition(Patungkuonu::Position{0, 0});
    sprite.SetPlaybackSpeed(5.0f);
    sprite.SetRange(0, 5);

    Patungkuonu::Engine engine(setting);
    engine.AddSprite(&sprite);
    sprite.UpdateRange(6, 11, Patungkuonu::Flip::FLIP_HORIZONTAL);
    engine.Run();

    return 0;
}
