// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_ENGINE_HPP_
#define INCLUDE_ENGINE_HPP_
#include <SDL2/SDL.h>
#include "setting.hpp"
#include "lib_export_options.hpp"

namespace Patungkuonu {  // namespace Patungkuonu

class LIB_EXPORT Engine {
 public:
  explicit Engine(const Setting& setting);
  ~Engine();
  void run();
 private:
  Setting m_setting;
  SDL_Window* m_window{nullptr};
  SDL_Surface* m_surface{nullptr};
  bool Initialize();
  void Cleanup();
};

}  // namespace Patungkuonu

#endif  // INCLUDE_ENGINE_HPP_
