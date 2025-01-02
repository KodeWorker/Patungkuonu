// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#pragma warning(disable: 4251)
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

class LIB_EXPORT GameObject {
 public:
  GameObject();
  ~GameObject();
  virtual void Update(float delta) = 0;
  virtual void Act(Controller* controller) = 0;
  virtual void Render(SDL_Renderer* renderer) = 0;
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
  void SetTime(float time) { m_time = time; }
  float GetTime() const { return m_time; }
  void SetActSpeed(float act_speed) { m_act_speed = act_speed; }
  float GetActSpeed() const { return m_act_speed; }
  void SetActive(bool active) { m_active = active; }
  bool GetActive() const { return m_active; }
  void SetCurrentState(int current_state) { m_current_state = current_state; }
  int GetCurrentState() const { return m_current_state; }
  void SetPreviousState(int previous_state) { m_previous_state = previous_state; }
  int GetPreviousState() const { return m_previous_state; }
  void SetCollideType(CollideType collide_type) { m_collide_type = collide_type; }
  CollideType GetCollideType() const { return m_collide_type; }

 private:
  std::string m_name;
  Position m_position;
  Size m_size;
  Sprite* m_sprite{nullptr};
  float m_time{0.0f};
  float m_act_speed{1.0f};
  bool m_active{false};
  int m_current_state{0};
  int m_previous_state{0};
  CollideType m_collide_type{COLLIDE_NONE};
};

class LIB_EXPORT Player : public GameObject {
 public:
  Player();
  ~Player();
  void Move(Position position);
  void Update(float delta) override;
  void Act(Controller* controller) override;
  void Render(SDL_Renderer* renderer) override;
  bool Collide(GameObject* object) override;
  // Setters and Getters
  void SetMoveSpeed(int move_speed) { m_move_speed = move_speed; }
  int GetMoveSpeed() const { return m_move_speed; }

 private:
  int m_move_speed{5};
};

}  // namespace Patungkuonu

#endif  // INCLUDE_OBJECT_HPP_
