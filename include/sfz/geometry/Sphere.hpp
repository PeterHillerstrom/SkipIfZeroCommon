#pragma once
#ifndef SFZ_GEOMETRY_SPHERE_HPP
#define SFZ_GEOMETRY_SPHERE_HPP

#include <string>
#include <iostream> // std::ostream
#include <functional> // std::hash

#include "sfz/Assert.hpp"
#include "sfz/math/Vector.hpp"

namespace sfz {

/**
 * @brief Class representing a Sphere.
 * @author Peter Hillerström
 */
class Sphere final {
public:
	// Constructors & destructors
	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	inline Sphere() noexcept = default;

	/**
	 * @sfz_assert_debug radius > 0
	 */
	inline Sphere(const vec3& center, float radius) noexcept;

	// Public member functions
	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	inline size_t hash() const noexcept;
	inline std::string to_string() const noexcept;
	inline vec3 closestPoint(const vec3& point) const noexcept;

	// Public getters/setters
	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	inline vec3 position() const noexcept { return mCenter; }
	inline float radius() const noexcept { return mRadius; }

	inline void position(const vec3& newPosition) noexcept { mCenter = newPosition; }
	inline void radius(float newRadius) noexcept;

private:
	// Private members
	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	vec3 mCenter;
	float mRadius;
};

// Non-member operators
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

inline std::ostream& operator<< (std::ostream& ostream, const Sphere& sphere) noexcept;

} // namespace sfz

// Specializations of standard library for sfz::Sphere
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

namespace std {

template<>
struct hash<sfz::Sphere> {
	inline size_t operator() (const sfz::Sphere& sphere) const noexcept;
};

} // namespace std

#include "sfz/geometry/Sphere.inl"
#endif