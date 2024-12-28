// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_SPRITE_HPP_
#define INCLUDE_SPRITE_HPP_
#include <SDL2/SDL.h>
#include <string>
#include <vector>

namespace Patungkuonu {  // namespace Patungkuonu

struct Size {
  int width;
  int height;
};

struct Position {
  int x;
  int y;
};

class Sprite {
 public:
  Sprite();
  ~Sprite();
  void Attach(SDL_Renderer* renderer);
  void Update(float delta);
  void Render();
  void SetName(const std::string& name) { m_name = name; }
  const std::string& GetName() const { return m_name; }
  void SetPath(const std::string& path) { m_path = path; }
  const std::string& GetPath() const { return m_path; }
  void SetSize(Size size) {
    m_width = size.width;
    m_height = size.height;
  }
  Size GetSize() const { return {m_width, m_height}; }
  void SetPosition(Position position) {
    m_x = position.x;
    m_y = position.y;
  }
  Position GetPosition() const { return {m_x, m_y}; }
  void SetPlaybackSpeed(float speed) { m_playback_speed = speed; }
  float GetPlaybackSpeed() const { return m_playback_speed; }

 private:
  std::string m_name = "";
  std::string m_path = "";
  int m_width = 0;
  int m_height = 0;
  int m_x = 0;
  int m_y = 0;
  float m_time = 0.0f;  // in seconds
  float m_playback_speed = 60.0f;  // 60 frames per second
  int m_current_frame = 0;
  int m_total_frames = 0;
  int m_begin_frame = 0;
  int m_end_frame = 0;
  std::vector<SDL_Rect> m_frames;
  SDL_Texture* m_texture{nullptr};
  SDL_Renderer* m_renderer{nullptr};
  SDL_Surface* m_surface{nullptr};
};

}  // namespace Patungkuonu

#endif  // INCLUDE_SPRITE_HPP_
