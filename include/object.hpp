// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#pragma warning(disable: 4251)
#ifndef INCLUDE_OBJECT_HPP_
#define INCLUDE_OBJECT_HPP_
#include <string>
#include <vector>
#include <memory>
#include "sprite.hpp"  // NOLINT
#include "controller.hpp"  // NOLINT
#include "lib_export_options.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

struct LIB_EXPORT Direction {
  float x;
  float y;
};

typedef enum LIB_EXPORT {
  COLLIDE_NONE,
  COLLIDE_RECT,
  COLLIDE_CIRCLE
} CollideType;

class LIB_EXPORT GameObject {
 public:
  GameObject();
  ~GameObject();
  void Update(float delta);
  void Render(SDL_Renderer* renderer);
  bool Collide(GameObject* object);
  virtual void Act(Controller* controller) = 0;
  // Setters and Getters
  void SetName(const std::string& name) { m_name = name; }
  const std::string& GetName() const { return m_name; }
  void SetPosition(Position position) {
    m_position.x = position.x;
    m_position.y = position.y;
    if (m_sprite != nullptr) {
      m_sprite->SetPosition(position);
    }
  }
  Position GetPosition() const { return {m_position.x, m_position.y}; }
  void SetSize(Size size) {
    m_size.width = size.width;
    m_size.height = size.height;
    if (m_sprite != nullptr) {
      m_sprite->SetRatio({static_cast<float>(size.width) / m_sprite->GetSize().width,
                          static_cast<float>(size.height) / m_sprite->GetSize().height});
    }
  }
  Size GetSize() const { return {m_size.width, m_size.height}; }
  void SetSprite(Sprite* sprite) {
    m_sprite = sprite;
    m_sprite->SetPosition(m_position);
    m_sprite->SetRatio({static_cast<float>(m_size.width) / m_sprite->GetSize().width,
                        static_cast<float>(m_size.height) / m_sprite->GetSize().height});
  }
  Sprite* GetSprite() { return m_sprite; }
  void SetTime(float time) { m_time = time; }
  float GetTime() const { return m_time; }
  void SetActSpeed(float act_speed) { m_act_speed = act_speed; }
  float GetActSpeed() const { return m_act_speed; }
  void SetActive(bool active) { m_active = active; }
  bool GetActive() const { return m_active; }
  void SetCollide(bool collide) { m_collide = collide; }
  bool GetCollide() const { return m_collide; }
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
  bool m_collide{false};
  CollideType m_collide_type{COLLIDE_NONE};
};

class LIB_EXPORT Character : public GameObject {
 public:
  Character();
  ~Character();
  void Act(Controller* controller) override;
  virtual void React(Controller* controller) = 0;
  // Setters and Getters
  void SetMoveSpeed(int move_speed) { m_move_speed = move_speed; }
  int GetMoveSpeed() const { return m_move_speed; }
  void SetMoveDirection(Direction move_direction) { m_move_direction = move_direction; }
  Direction GetMoveDirection() const { return {m_move_direction.x, m_move_direction.y}; }
  void SetMoving(bool moving) { m_moving = moving; }
  bool GetMoving() const { return m_moving; }
  void SetAttacking(bool attacking) { m_attacking = attacking; }
  bool GetAttacking() const { return m_attacking; }
  void SetCurrentState(int current_state) { m_current_state = current_state; }
  int GetCurrentState() const { return m_current_state; }
  void SetPreviousState(int previous_state) { m_previous_state = previous_state; }
  int GetPreviousState() const { return m_previous_state; }

 private:
  int m_move_speed{5};
  Direction m_move_direction{0, 0};
  bool m_moving{false};
  bool m_attacking{false};
  int m_current_state{0};
  int m_previous_state{0};
};

class LIB_EXPORT Player : public Character {
 public:
  Player();
  ~Player();
  void Move();
  void UpdateStateFrames();
  void React(Controller* controller) override;
};

class LIB_EXPORT Enemy : public Character {
 public:
  Enemy();
  ~Enemy();
  void React(Controller* controller) override;
};

}  // namespace Patungkuonu

#endif  // INCLUDE_OBJECT_HPP_
