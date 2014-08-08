#pragma once
#ifndef SFZ_MATH_ALIGNMENT_HPP
#define SFZ_MATH_ALIGNMENT_HPP

namespace sfz {

	/**
	 * @brief A simple enum used to determine if something is left, center or right-aligned horizontally.
	 *
	 * The different values are considered to have different distance from each other. The distance from LEFT to
	 * CENTER is one unit, the distance from LEFT to RIGHT is two units. The formula for calculating the distance is
	 * 'destination - origin'. Therefore going from LEFT to RIGHT is the positive direction, going from RIGHT to LEFT
	 * is the negative direction.
	 *
	 * @author Peter Hillerström <peter@hstroem.se>
	 */
	enum class HorizontalAlign : char {
		LEFT = -1, 
		CENTER = 0, 
		RIGHT = 1
	};

	/**
	 * @brief A simple enum used to determine if something is bottom, middle or top-aligned vertically.
	 *
	 * The different values are considered to have different distance from each other. The distance from BOTTOM to
	 * MIDDLE is one unit, the distance from BOTTOM to TOP is two units. The formula for calculating the distance is
	 * 'destination - origin'. Therefore going from BOTTOM to TOP is the positive direction, going from TOP to BOTTOM
	 * is the negative direction.
	 *
	 * author Peter Hillerström <peter@hstroem.se>
	 */
	enum class VerticalAlign : char {
		BOTTOM = -1, 
		MIDDLE = 0, 
		TOP = 1
	};

	/**
	 * @brief Calculates the distance between two HorizontalAlign enums.
	 * 
	 * Calculates and returns the distance between two enum values as defined by the enums. The answer will be signed
	 * and may have a positive or negative value depending on the 'direction'. 
	 *
	 * @param origin the origin enum
	 * @param destination the destination enum
	 * @return the distance between the two enums
	 */
	char distance(HorizontalAlign origin, HorizontalAlign destination) {
		return static_cast<char>(destination) - static_cast<char>(origin);
	}

	/**
	 * @brief Calculates the distance between two VerticalAlign enums.
	 * 
	 * Calculates and returns the distance between two enum values as defined by the enums. The answer will be signed
	 * and may have a positive or negative value depending on the 'direction'. 
	 *
	 * @param origin the origin enum
	 * @param destination the destination enum
	 * @return the distance between the two enums
	 */
	char distance(VerticalAlign origin, VerticalAlign destination) {
		return static_cast<char>(destination) - static_cast<char>(origin);
	}

	/**
	 * @brief Calculates the new position when changing alignment.
	 *
	 * Beware that this function will probably cause problems in a coordinate system with inverted y-axis (i.e. (0,0)
	 * in upper left corner).
	 * 
	 * @param oldPosition the old position
	 * @param size the size of the object in the desired axis
	 * @param oldAlignment the old alignment
	 * @param newAlignment the new alignment
	 * @return the new position
	 */
	template<typename T, typename Align>
	T calculateNewPosition(T oldPosition, T size, Align oldAlignment, Align newAlignment) {
		// Calculate the denominator. If the align distance is 2 we don't want to do anything to the size, i.e. divide
		// by 1. If the distance is 1 we want to adjust by half the size, so we divide by 2. 
		char denominator;
		switch(distance(oldAlignment, newAlignment)) {
		case 0:
			// origin == destination, so do nothing.
			return oldPosition;
		case -2:
			denominator = -1;
			break;
		case -1:
			denominator = -2;
			break;
		case 1:
			denominator = 2;
			break;
		case 2:
			denominator = 1;
			break;
		default:
			throw std::logic_error{"This should not be possible."};
		}
		// Adjust the position with the size of the object divided by the previously calculated denominator.
		return oldPosition + (size / static_cast<T>(denominator));
	}
 }
#endif