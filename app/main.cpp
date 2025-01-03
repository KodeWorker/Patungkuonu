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
    setting.SetFrameRate(30);

    Patungkuonu::Sprite player_sprite;
    player_sprite.SetPath("../assets/Cute_Fantasy_Free/Player/Player.png");
    player_sprite.SetSize(Patungkuonu::Size{32, 32});
    player_sprite.SetPlaybackSpeed(5.0f);
    player_sprite.SetRange(0, 5);

    Patungkuonu::Player player;
    player.SetName("Player");
    player.SetPosition(Patungkuonu::Position{0, 0});
    player.SetSize(Patungkuonu::Size{64, 64});
    player.SetCollideType(Patungkuonu::CollideType::COLLIDE_CIRCLE);
    player.SetSprite(&player_sprite);
    player.SetActSpeed(0.1f);

    Patungkuonu::Sprite slime_sprite;
    slime_sprite.SetPath("../assets/Cute_Fantasy_Free/Enemies/Slime.png");
    slime_sprite.SetSize(Patungkuonu::Size{32, 32});
    slime_sprite.SetPlaybackSpeed(5.0f);
    slime_sprite.SetRange(0, 3);

    Patungkuonu::Enemy enemy;
    enemy.SetName("Slime");
    enemy.SetPosition(Patungkuonu::Position{100, 0});
    enemy.SetSize(Patungkuonu::Size{64, 64});
    enemy.SetCollideType(Patungkuonu::CollideType::COLLIDE_CIRCLE);
    enemy.SetSprite(&slime_sprite);
    enemy.SetActSpeed(0.1f);

    Patungkuonu::Engine engine(setting);
    engine.AddObject(&enemy);
    engine.AddObject(&player);
    engine.Run();

    return 0;
}
