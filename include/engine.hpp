// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_ENGINE_HPP_
#define INCLUDE_ENGINE_HPP_
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <memory>
#include <deque>
#include "setting.hpp"  // NOLINT
#include "object.hpp"  // NOLINT
#include "controller.hpp"  // NOLINT
#include "lib_export_options.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

class LIB_EXPORT Engine {
 public:
  explicit Engine(const Setting& setting);
  ~Engine();
  void AddObject(GameObject* object);
  void Run();
 private:
  Setting m_setting;
  std::unique_ptr<SDL_Event> m_event;
  std::unique_ptr<KeyboardController> m_keyboard_controller;
  SDL_Window* m_window{nullptr};
  SDL_Renderer* m_renderer{nullptr};
  std::deque<GameObject*> m_objects;
  bool Initialize();
  void Cleanup();
};

}  // namespace Patungkuonu

#endif  // INCLUDE_ENGINE_HPP_
