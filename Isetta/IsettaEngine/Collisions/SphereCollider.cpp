/*
 * Copyright (c) 2018 Isetta
 */
#include "Collisions/SphereCollider.h"
#include "Collisions/BoxCollider.h"
#include "Collisions/CapsuleCollider.h"
#include "Collisions/CollisionsModule.h"

#include "Collisions/Ray.h"
#include "Core/Debug/DebugDraw.h"
#include "Core/Math/Matrix4.h"
#include "Scene/Transform.h"

namespace Isetta {
void SphereCollider::Update() {
  DebugDraw::AxisSphere(
      Math::Matrix4::Translate(GetTransform()->GetWorldPos() + center) *
          Math::Matrix4::Scale(
              Math::Vector3{radius * GetTransform()->GetWorldScale().Max()}),
      debugColor, debugColor, debugColor);
}

bool SphereCollider::Raycast(const Ray& ray, RaycastHit* const hitInfo,
                             float maxDistance) {
  Math::Vector3 to = ray.GetOrigin() - GetWorldCenter();
  float b = Math::Vector3::Dot(to, ray.GetDirection());
  float c = Math::Vector3::Dot(to, to) - GetWorldRadius() * GetWorldRadius();
  if (c > 0.0f && b > 0.0f) {
    return false;
  }
  float discrim = b * b - c;
  if (discrim < 0.0f) return false;
  discrim = Math::Util::Sqrt(discrim);
  float t = -b - discrim;
  if (t < 0.f) t = -b + discrim;
  Math::Vector3 pt = ray.GetPoint(t);
  RaycastHitCtor(hitInfo, t, pt, pt - GetWorldCenter());
  return true;
}

INTERSECTION_TEST(SphereCollider)
}  // namespace Isetta
