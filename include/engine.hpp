// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_ENGINE_HPP_
#define INCLUDE_ENGINE_HPP_
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <deque>
#include "setting.hpp"  // NOLINT
#include "sprite.hpp"  // NOLINT
#include "lib_export_options.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

class LIB_EXPORT Engine {
 public:
  explicit Engine(const Setting& setting);
  ~Engine();
  void AddSprite(Sprite* sprite);
  void Run();
 private:
  Setting m_setting;
  SDL_Window* m_window{nullptr};
  SDL_Renderer* m_renderer{nullptr};
  std::deque<Sprite*> m_sprites;
  bool Initialize();
  void Cleanup();
};

}  // namespace Patungkuonu

#endif  // INCLUDE_ENGINE_HPP_
