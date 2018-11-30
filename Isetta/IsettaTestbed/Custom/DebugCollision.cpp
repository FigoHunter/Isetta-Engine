/*
 * Copyright (c) 2018 Isetta
 */
#include "DebugCollision.h"

namespace Isetta {
void DebugCollision::OnEnable() {
  colliders = entity->GetComponents<Collider>();
  handler = entity->GetComponent<CollisionHandler>();
  enterHandle =
      handler->RegisterOnEnter(BIND_1(DebugCollision::OnCollisionEnter, this));
  exitHandle =
      handler->RegisterOnExit(BIND_1(DebugCollision::OnCollisionExit, this));
}
void DebugCollision::OnDisable() {
  handler->UnregisterOnEnter(enterHandle);
  handler->UnregisterOnExit(exitHandle);
}
void DebugCollision::OnCollisionEnter(Collider* const col) {
  collisions++;
  for (auto& c : colliders) {
    c->debugColor = Color::red;
  }
}
void DebugCollision::OnCollisionExit(Collider* const other) {
  collisions--;
  if (collisions == 0) {
    for (auto& c : colliders) {
      c->debugColor = Color::green;
    }
  }
}
}  // namespace Isetta
