// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include "controller.hpp"  // NOLINT
#include "logger.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

Controller::Controller() {
}

Controller::~Controller() {
}

KeyboardController::KeyboardController() {
}

KeyboardController::~KeyboardController() {
}

void KeyboardController::Update(SDL_Event* event) {
    // Update the keyboard controller
    switch (event->type) {
        case SDL_KEYDOWN:
            // Handle key down event
            m_key_states[event->key.keysym.sym] = KeyState::PRESSED;
            break;
        case SDL_KEYUP:
            // Handle key up event
            m_key_states[event->key.keysym.sym] = KeyState::RELEASED;
            break;
        default:
            break;
    }
}

bool KeyboardController::IsPressed(SDL_Keycode key) {
    // Implement IsPressed
    if (m_key_states.find(key) != m_key_states.end()) {
        return m_key_states[key] == KeyState::PRESSED;
    }
    return false;
}

bool KeyboardController::IsReleased(SDL_Keycode key) {
    // Implement IsReleased
    if (m_key_states.find(key) != m_key_states.end()) {
        return m_key_states[key] == KeyState::RELEASED;
    }
    return false;
}

}  // namespace Patungkuonu
