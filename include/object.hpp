// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_OBJECT_HPP_
#define INCLUDE_OBJECT_HPP_
#include <string>
#include <vector>
#include "sprite.hpp"  // NOLINT
#include "controller.hpp"  // NOLINT
#include "lib_export_options.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

typedef enum LIB_EXPORT {
  COLLIDE_NONE,
  COLLIDE_RECT,
  COLLIDE_CIRCLE
} CollideType;

class GameObject {
 public:
  GameObject();
  ~GameObject();
  virtual void Update(SDL_Event* event) = 0;
  virtual bool Collide(GameObject* object) = 0;
  // Setters and Getters
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
  void SetSprite(Sprite* sprite) { m_sprite = sprite; }
  Sprite* GetSprite() { return m_sprite; }
  void SetCollideType(CollideType collide_type) { m_collide_type = collide_type; }
  CollideType GetCollideType() const { return m_collide_type; }
  void SetCollideCoefficients(const std::vector<float>& coefficients) {
    m_collide_coefficients = coefficients;
  }
  const std::vector<float>& GetCollideCoefficients() const { return m_collide_coefficients; }

 private:
  std::string m_name;
  Position m_position;
  Size m_size;
  Sprite* m_sprite{nullptr};
  CollideType m_collide_type{COLLIDE_NONE};
  std::vector<float> m_collide_coefficients;
};

class LIB_EXPORT Player : public GameObject {
 public:
  Player();
  ~Player();
  void Move(Position position);
  void Update(SDL_Event* event) override;
  bool Collide(GameObject* object) override;
  // Setters and Getters
  void SetMoveSpeed(int move_speed) { m_move_speed = move_speed; }
  int GetMoveSpeed() const { return m_move_speed; }

 private:
  int m_move_speed{5};
  KeyboardController m_controller;
};

}  // namespace Patungkuonu

#endif  // INCLUDE_OBJECT_HPP_
