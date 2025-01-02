// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include <typeinfo>
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

void Player::Update(float delta) {
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

void Player::Act(Controller* controller) {
    // Act the player
    if (!GetActive()) {
        return;
    }
    if (typeid(*controller) == typeid(KeyboardController)) {
        KeyboardController* keyboard_controller = dynamic_cast<KeyboardController*>(controller);
        // 8-directional movement        
        if (keyboard_controller->IsPressed(SDLK_w) && keyboard_controller->IsPressed(SDLK_a)) {
            SetCurrentState(1);
            GetSprite()->SetRange(12, 17);
            Move({GetPosition().x - static_cast<int>(GetMoveSpeed() * 0.7071),
                  GetPosition().y - static_cast<int>(GetMoveSpeed() * 0.7071)});
        } else if (keyboard_controller->IsPressed(SDLK_w) && keyboard_controller->IsPressed(SDLK_d)) {
            SetCurrentState(1);
            GetSprite()->SetRange(12, 17);
            Move({GetPosition().x + static_cast<int>(GetMoveSpeed() * 0.7071),
                  GetPosition().y - static_cast<int>(GetMoveSpeed() * 0.7071)});
        } else if (keyboard_controller->IsPressed(SDLK_s) && keyboard_controller->IsPressed(SDLK_a)) {
            SetCurrentState(2);
            GetSprite()->SetRange(18, 23);
            Move({GetPosition().x - static_cast<int>(GetMoveSpeed() * 0.7071),
                  GetPosition().y + static_cast<int>(GetMoveSpeed() * 0.7071)});
        } else if (keyboard_controller->IsPressed(SDLK_s) && keyboard_controller->IsPressed(SDLK_d)) {
            SetCurrentState(2);
            GetSprite()->SetRange(18, 23);
            Move({GetPosition().x + static_cast<int>(GetMoveSpeed() * 0.7071),
                  GetPosition().y + static_cast<int>(GetMoveSpeed() * 0.7071)});
        } else if (keyboard_controller->IsPressed(SDLK_w)) {
            SetCurrentState(1);
            GetSprite()->SetRange(12, 17);
            Move({GetPosition().x, GetPosition().y - GetMoveSpeed()});
        } else if (keyboard_controller->IsPressed(SDLK_s)) {
            SetCurrentState(2);
            GetSprite()->SetRange(18, 23);
            Move({GetPosition().x, GetPosition().y + GetMoveSpeed()});
        } else if (keyboard_controller->IsPressed(SDLK_a)) {
            SetCurrentState(3);
            GetSprite()->SetRange(6, 11);
            GetSprite()->SetFlip(SpriteFlip::FLIP_HORIZONTAL);
            Move({GetPosition().x - GetMoveSpeed(), GetPosition().y});
        } else if (keyboard_controller->IsPressed(SDLK_d)) {
            SetCurrentState(4);
            GetSprite()->SetRange(6, 11);
            GetSprite()->SetFlip(SpriteFlip::FLIP_NONE);
            Move({GetPosition().x + GetMoveSpeed(), GetPosition().y});
        } else{
            SetCurrentState(0);
            GetSprite()->SetRange(0, 5);
        }
    } else {
        Logger::GetInstance().error("Invalid controller type");
    }    
    // State changed
    if(GetPreviousState() != GetCurrentState()) {        
        GetSprite()->UpdateFrames();
    }
    SetPreviousState(GetCurrentState());
    SetActive(false);
}

void Player::Render(SDL_Renderer* renderer) {
    // Render the player
    if (GetSprite() != nullptr) {
        GetSprite()->Render(renderer);
    } else {
        Logger::GetInstance().error("Player sprite is not set");
    }
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
