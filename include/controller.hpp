// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_CONTROLLER_HPP_
#define INCLUDE_CONTROLLER_HPP_
#include <SDL2/SDL.h>
#include "lib_export_options.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

class Controller {
 public:
  Controller();
  ~Controller();
  virtual void Update(SDL_Event* event) = 0;
};

class LIB_EXPORT KeyboardController : public Controller {
 public:
  KeyboardController();
  ~KeyboardController();
  bool IsPressed(SDL_Keycode key);
  bool IsReleased(SDL_Keycode key);
  void Update(SDL_Event* event) override;
};

}  // namespace Patungkuonu

#endif  // INCLUDE_CONTROLLER_HPP_
