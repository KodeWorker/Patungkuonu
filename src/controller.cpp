// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include "controller.hpp"  // NOLINT

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
    // TODO(kodeworker): Update the keyboard controller
}

bool KeyboardController::IsPressed(SDL_Keycode key) {
    // TODO(kodeworker): Implement IsPressed
    return false;
}

bool KeyboardController::IsReleased(SDL_Keycode key) {
    // TODO(kodeworker): Implement IsReleased
    return false;
}

}  // namespace Patungkuonu
