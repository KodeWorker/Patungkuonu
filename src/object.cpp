// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include <typeinfo>
#include "object.hpp"  // NOLINT
#include "logger.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

void GameObject::Update(float delta) {
    // Update the player
    if (GetSprite() != nullptr) {
        GetSprite()->Update(delta);
        SetTime(GetTime() + delta);
        if (GetTime() >= GetActSpeed()) {
            SetTime(0.0f);
            SetActive(true);
        }
    } else {
        Logger::GetInstance().error("Player sprite is not set");
    }
}

void GameObject::Render(SDL_Renderer* renderer) {
    // Render the player
    if (GetSprite() != nullptr) {
        GetSprite()->Render(renderer);
    } else {
        Logger::GetInstance().error("Player sprite is not set");
    }
}

bool GameObject::Collide(GameObject* object) {
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

Character::Character() {
}

Character::~Character() {
}

void Character::Act(Controller* controller) {
    // Act the player
    if (!GetActive()) {
        return;
    }
    React(controller);
    // State changed
    if (GetPreviousState() != GetCurrentState()) {
        GetSprite()->UpdateFrames();
    }
    SetPreviousState(GetCurrentState());
    SetActive(false);
}

Player::Player() {
    SetActSpeed(0.1f);
}

Player::~Player() {
}

void Player::React(Controller* controller) {
    if (typeid(*controller) == typeid(KeyboardController)) {
        KeyboardController* keyboard_controller = dynamic_cast<KeyboardController*>(controller);
        // 8-directional movement
        if (keyboard_controller->IsPressed(SDLK_w) && keyboard_controller->IsPressed(SDLK_a)) {
            SetMoving(true);
            SetMoveDirection({-0.7071f, -0.7071f});
        } else if (keyboard_controller->IsPressed(SDLK_w) && keyboard_controller->IsPressed(SDLK_d)) {
            SetMoving(true);
            SetMoveDirection({0.7071f, -0.7071f});
        } else if (keyboard_controller->IsPressed(SDLK_s) && keyboard_controller->IsPressed(SDLK_a)) {
            SetMoving(true);
            SetMoveDirection({-0.7071f, 0.7071f});
        } else if (keyboard_controller->IsPressed(SDLK_s) && keyboard_controller->IsPressed(SDLK_d)) {
            SetMoving(true);
            SetMoveDirection({0.7071f, 0.7071f});
        } else if (keyboard_controller->IsPressed(SDLK_w)) {
            SetMoving(true);
            SetMoveDirection({0, -1});
        } else if (keyboard_controller->IsPressed(SDLK_s)) {
            SetMoving(true);
            SetMoveDirection({0, 1});
        } else if (keyboard_controller->IsPressed(SDLK_a)) {
            SetMoving(true);
            SetMoveDirection({-1, 0});
        } else if (keyboard_controller->IsPressed(SDLK_d)) {
            SetMoving(true);
            SetMoveDirection({1, 0});
        } else {
            SetMoving(false);
        }
    } else {
        Logger::GetInstance().error("Invalid controller type");
    }
    if (!GetAttacking()) {
        Move();
    }
    UpdateStateFrames();
}

void Player::Move() {
    // Move the player
    if (GetMoving()) {
        SetPosition({GetPosition().x + static_cast<int>(GetMoveDirection().x * GetMoveSpeed()),
            GetPosition().y + static_cast<int>(GetMoveDirection().y * GetMoveSpeed())});
        if (GetMoveDirection().x > 0) {
            SetCurrentState(4);
            GetSprite()->SetFlip(SpriteFlip::FLIP_NONE);
        } else if (GetMoveDirection().x < 0) {
            SetCurrentState(4);
            GetSprite()->SetFlip(SpriteFlip::FLIP_HORIZONTAL);
        } else if (GetMoveDirection().y > 0) {
            SetCurrentState(3);
        } else if (GetMoveDirection().y < 0) {
            SetCurrentState(5);
        }
    } else {
        if (GetMoveDirection().x > 0) {
            SetCurrentState(1);
            GetSprite()->SetFlip(SpriteFlip::FLIP_NONE);
        } else if (GetMoveDirection().x < 0) {
            SetCurrentState(1);
            GetSprite()->SetFlip(SpriteFlip::FLIP_HORIZONTAL);
        } else if (GetMoveDirection().y > 0) {
            SetCurrentState(0);
        } else if (GetMoveDirection().y < 0) {
            SetCurrentState(2);
        }
    }
}

void Player::UpdateStateFrames() {
    // Update Frames
    switch (GetCurrentState()) {
    case 0:
        GetSprite()->SetRange(0, 5);
        break;
    case 1:
        GetSprite()->SetRange(6, 11);
        break;
    case 2:
        GetSprite()->SetRange(12, 17);
        break;
    case 3:
        GetSprite()->SetRange(18, 23);
        break;
    case 4:
        GetSprite()->SetRange(24, 29);
        break;
    case 5:
        GetSprite()->SetRange(30, 35);
        break;
    case 6:
        GetSprite()->SetRange(36, 39);
        break;
    case 7:
        GetSprite()->SetRange(42, 45);
        break;
    case 8:
        GetSprite()->SetRange(48, 51);
        break;
    case 9:
        GetSprite()->SetRange(54, 57);
        break;
    default:
        break;
    }
}

Enemy::Enemy() {
}

Enemy::~Enemy() {
}

void Enemy::React(Controller* controller) {
    // TODO(kodeworker): Implement enemy AI
}

}  // namespace Patungkuonu
