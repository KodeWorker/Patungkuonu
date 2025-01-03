// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#pragma warning(disable: 4251)
#ifndef INCLUDE_SPRITE_HPP_
#define INCLUDE_SPRITE_HPP_
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "lib_export_options.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

struct LIB_EXPORT Size {
  int width;
  int height;
};

struct LIB_EXPORT Position {
  int x;
  int y;
};

struct LIB_EXPORT Ratio {
  float x;
  float y;
};

typedef enum LIB_EXPORT {
  FLIP_NONE = SDL_FLIP_NONE,
  FLIP_HORIZONTAL = SDL_FLIP_HORIZONTAL,
  FLIP_VERTICAL = SDL_FLIP_VERTICAL
} SpriteFlip;

class LIB_EXPORT Sprite {
 public:
  Sprite();
  ~Sprite();
  void Load(SDL_Renderer* renderer);
  void Render(SDL_Renderer* renderer);
  void Update(float delta);
  void UpdateFrames(size_t start_frame, size_t end_frame);
  void UpdateFrames() { UpdateFrames(m_start_frame, m_end_frame); }
  // Setters and Getters
  void SetPath(const std::string& path) { m_path = path; }
  const std::string& GetPath() const { return m_path; }
  void SetSize(Size size) {
    m_size.width = size.width;
    m_size.height = size.height;
  }
  Size GetSize() const { return {m_size.width, m_size.height}; }
  void SetPosition(Position position) {
    m_position.x = position.x;
    m_position.y = position.y;
  }
  Position GetPosition() const { return {m_position.x, m_position.y}; }
  void SetPlaybackSpeed(float speed) { m_playback_speed = speed; }
  float GetPlaybackSpeed() const { return m_playback_speed; }
  void SetRange(size_t start, size_t end) {
    m_start_frame = start;
    m_end_frame = end;
  }
  void SetFlip(SpriteFlip flip) { m_flip = flip; }
  SpriteFlip GetFlip() const { return m_flip; }
  void SetRatio(Ratio ratio) {
    m_ratio.x = ratio.x;
    m_ratio.y = ratio.y;
  }
  Ratio GetRatio() const { return {m_ratio.x, m_ratio.y}; }

 private:
  std::string m_path = "";
  Size m_size = {0, 0};
  Size m_texture_size = {0, 0};
  Position m_position = {0, 0};
  Ratio m_ratio{1.0f, 1.0f};
  float m_time = 0.0f;  // in seconds
  float m_playback_speed = 60.0f;  // 60 frames per second
  size_t m_current_frame = 0;
  size_t m_total_frames = 0;
  size_t m_start_frame = 0;
  size_t m_end_frame = 0;
  SpriteFlip m_flip = FLIP_NONE;
  std::vector<SDL_Rect> m_vec_frames;
  SDL_Texture* m_texture{nullptr};
};

}  // namespace Patungkuonu

#endif  // INCLUDE_SPRITE_HPP_
