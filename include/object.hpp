// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_OBJECT_HPP_
#define INCLUDE_OBJECT_HPP_
#include <string>
#include "sprite.hpp"  // NOLINT
#include "lib_export_options.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

class object {
 public:
  object();
  ~object();
  void SetName(const std::string& name) { m_name = name; }
  const std::string& GetName() const { return m_name; }
  void SetPosition(Position position) {
    m_position.x = position.x;
    m_position.y = position.y;
  }
  Position GetPosition() const { return {m_position.x, m_position.y}; }
  void SetSize(Size size) {
    m_size.width = size.width;
    m_size.height = size.height;
  }
  Size GetSize() const { return {m_size.width, m_size.height}; }
  void SetSprite(const Sprite& sprite) { m_sprite = sprite; }
  const Sprite& GetSprite() const { return m_sprite; }
  bool Collide(object& object);  // TODO(kodeworker): Implement this function
 private:
  std::string m_name;
  Position m_position;
  Size m_size;
  Sprite m_sprite;
};

}  // namespace Patungkuonu

#endif  // INCLUDE_OBJECT_HPP_
