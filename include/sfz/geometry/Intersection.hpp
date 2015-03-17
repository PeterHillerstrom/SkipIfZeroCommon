#pragma once
#ifndef SFZ_GEOMETRY_COLLISION_DETECTION_HPP
#define SFZ_GEOMETRY_COLLISION_DETECTION_HPP

#include "sfz/geometry/AABB.hpp"
#include "sfz/geometry/OBB.hpp"
#include "sfz/geometry/Plane.hpp"
#include "sfz/geometry/Sphere.hpp"

#include "sfz/MSVC12HackON.hpp"

namespace sfz {

// Point inside primitive tests
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool pointInside(const AABB& box, const vec3f& point) noexcept;
bool pointInside(const OBB& box, const vec3f& point) noexcept;
bool pointInside(const Sphere& sphere, const vec3f& point) noexcept;

// Primitive vs primitive tests (same type)
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool intersects(const AABB& boxA, const AABB& boxB) noexcept;
bool intersects(const OBB& boxA, const OBB& boxB) noexcept;
bool intersects(const Sphere& sphereA, const Sphere& sphereB) noexcept;

// Plane & AABB tests
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool intersects(const Plane& plane, const AABB& aabb) noexcept;

// Plane & OBB tests
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool intersects(const Plane& plane, const OBB& obb) noexcept;

// Plane & Sphere tests
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool intersects(const Plane& plane, const Sphere& sphere) noexcept;
bool intersects(const Sphere& sphere, const Plane& plane) noexcept;
/** @brief Checks whether Sphere intersects with or is in positive half-space of plane. */
bool abovePlane(const Plane& plane, const Sphere& sphere) noexcept;
/** @brief Checks whether Sphere intersects with or is in negative half-space of plane. */
bool belowPlane(const Plane& plane, const Sphere& sphere) noexcept;


} // namespace sfz

#include "sfz/MSVC12HackOFF.hpp"

#endif