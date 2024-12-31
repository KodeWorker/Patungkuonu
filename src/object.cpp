// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include "object.hpp"  // NOLINT
#include "logger.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

Player::Player() {
}

Player::~Player() {
}

void Player::Move(Position position) {
    SetPosition(position);
    GetSprite()->SetPosition(position);
}

void Player::Update(SDL_Event* event) {
    // TODO(kodeworker): Update the player
    m_controller.Update(event);
    // TODO(kodeworker): 8 - direction movement
}

bool Player::Collide(GameObject* object) {
    if (GetCollideType() == CollideType::COLLIDE_NONE ||
        object->GetCollideType() == CollideType::COLLIDE_NONE) {
        return false;
    } else if (GetCollideType() == CollideType::COLLIDE_RECT &&
               object->GetCollideType() == CollideType::COLLIDE_RECT) {
        // TODO(kodeworker): Implement collision detection for rectangles
        return false;
    } else if (GetCollideType() == CollideType::COLLIDE_CIRCLE &&
               object->GetCollideType() == CollideType::COLLIDE_CIRCLE) {
        // TODO(kodeworker): Implement collision detection for circles
        return false;
    } else if (GetCollideType() == CollideType::COLLIDE_RECT &&
               object->GetCollideType() == CollideType::COLLIDE_CIRCLE) {
        // TODO(kodeworker): Implement collision detection for rectangle and circle
        return false;
    } else if (GetCollideType() == CollideType::COLLIDE_CIRCLE &&
               object->GetCollideType() == CollideType::COLLIDE_RECT) {
        // TODO(kodeworker): Implement collision detection for circle and rectangle
        return false;
    } else {
        Logger::GetInstance().error("Invalid collision type");
        return false;
    }
}

}  // namespace Patungkuonu
