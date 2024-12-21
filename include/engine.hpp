// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_ENGINE_HPP_
#define INCLUDE_ENGINE_HPP_
#include <SDL2/SDL.h>
#include <string>
#include "lib_export_options.hpp"

namespace Patungkuonu {  // namespace Patungkuonu

class LIB_EXPORT Engine {
 public:
  Engine();
  ~Engine();
  void run();
 private:
  std::string m_window_name{"Engine"};
  int m_window_width{800};
  int m_window_height{600};
  SDL_Window* m_window{nullptr};
  SDL_Surface* m_surface{nullptr};
  bool Initialize();
  void Cleanup();
};

}  // namespace Patungkuonu

#endif  // INCLUDE_ENGINE_HPP_
