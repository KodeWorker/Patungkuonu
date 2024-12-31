// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include "setting.hpp"  // NOLINT
#include "engine.hpp"  // NOLINT
#include "sprite.hpp"  // NOLINT
#include "object.hpp"  // NOLINT

int main(int argc, char* argv[]) {
    Patungkuonu::Setting setting;
    setting.SetWindowName("Demo");
    setting.SetWindowWidth(1024);
    setting.SetWindowHeight(768);

    Patungkuonu::Sprite sprite;
    sprite.SetPath("../assets/Cute_Fantasy_Free/Player/Player.png");
    sprite.SetSize(Patungkuonu::Size{32, 32});
    sprite.SetPosition(Patungkuonu::Position{0, 0});
    sprite.SetPlaybackSpeed(5.0f);
    sprite.SetRange(0, 5);
    sprite.SetRatio(2.0f);

    Patungkuonu::Player player;
    player.SetName("Player");
    player.SetPosition(Patungkuonu::Position{0, 0});
    player.SetSize(Patungkuonu::Size{64, 64});
    player.SetCollideType(Patungkuonu::CollideType::COLLIDE_CIRCLE);
    player.SetCollideCoefficients({.8f});
    player.SetSprite(&sprite);

    Patungkuonu::Engine engine(setting);
    engine.AddObject(&player);
    engine.Run();

    return 0;
}
