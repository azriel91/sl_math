/*=============================================================================

	Library: Silver

	Copyright (c) Azriel Hoh

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

=============================================================================*/

#ifndef __SL_MATH__POINT_HPP
#define __SL_MATH__POINT_HPP

namespace sl {
namespace math {

template<class T, int N>
class Point {
protected:
	T values[N];

public:
	Point(const T val = 0);
	Point(const T other[N]); // this notation means, there are N number of T arguments
	Point(const Point<T, N> &other);
	virtual ~Point();

	/**
	 * Checks if this Point is equivalent to the passed in Point
	 *
	 * @param other the Point to compare against
	 */
	bool operator==(const Point<T, N> &other) const;
	/**
	 * Checks if this Point is not equivalent to the passed in Point
	 *
	 * @param other the Point to compare against
	 */
	bool operator!=(const Point<T, N> &other) const;
	/**
	 * Retrieves the value at the specified dimension index
	 *
	 * @param n the index of the dimension to retrieve the value of
	 */
	bool operator[](const int n) const;
	/**
	 * Adds the passed in value to each of the dimensions in this Point.
	 * This function does not modify this Point.
	 *
	 * @param val the value to add
	 */
	Point<T, N> operator+(const T &val) const;
	/**
	 * Adds the component values of the passed in Point to this Point's components.
	 * This function does not modify this Point.
	 *
	 * @param other the Point whose components to add
	 */
	Point<T, N> operator+(const Point<T, N> &other) const;
	/**
	 * Subtracts the passed in value from each of the dimensions in this Point.
	 * This function does not modify this Point.
	 *
	 * @param val the value to subtract
	 */
	Point<T, N> operator-(const T &val) const;
	/**
	 * Subtracts the component values of the passed in Point from this Point's components.
	 * This function does not modify this Point.
	 *
	 * @param other the Point whose components to subtract
	 */
	Point<T, N> operator-(const Point<T, N> &other) const;
	/**
	 * Multiplies the passed in value to each of the dimensions in this Point.
	 * This function does not modify this Point.
	 *
	 * @param val the value to add
	 */
	Point<T, N> operator*(const T &val) const;
	/**
	 * Multiplies the component values of the passed in Point to this Point's components.
	 * This function does not modify this Point.
	 *
	 * @param other the Point whose components to add
	 */
	Point<T, N> operator*(const Point<T, N> &other) const;
	/**
	 * Divides the passed in value from each of the dimensions in this Point.
	 * This function does not modify this Point.
	 *
	 * @param val the divisor
	 */
	Point<T, N> operator/(const T &val) const;
	/**
	 * Divides the component values of the passed in Point from this Point's components.
	 * This function does not modify this Point.
	 *
	 * @param other the Point whose components to be divisors
	 */
	Point<T, N> operator/(const Point<T, N> &other) const;

	// The following functions modify state of the original Point
	/**
	 * Adds the passed in value to each of the dimensions in this Point
	 * This function modifies the values in this Point.
	 *
	 * @param val the value to add
	 */
	Point<T, N> operator+=(const T &val);
	/**
	 * Adds the component values of the passed in Point to this Point's components
	 * This function modifies the values in this Point.
	 *
	 * @param other the Point whose components to add
	 */
	Point<T, N> operator+=(const Point<T, N> &other);
	/**
	 * Subtracts the passed in value from each of the dimensions in this Point
	 * This function modifies the values in this Point.
	 *
	 * @param val the value to subtract
	 */
	Point<T, N> operator-=(const T &val);
	/**
	 * Subtracts the component values of the passed in Point from this Point's components
	 * This function modifies the values in this Point.
	 *
	 * @param other the Point whose components to subtract
	 */
	Point<T, N> operator-=(const Point<T, N> &other);
	/**
	 * Multiplies the passed in value to each of the dimensions in this Point
	 * This function modifies the values in this Point.
	 *
	 * @param val the value to add
	 */
	Point<T, N> operator*=(const T &val);
	/**
	 * Multiplies the component values of the passed in Point to this Point's components
	 * This function modifies the values in this Point.
	 *
	 * @param other the Point whose components to add
	 */
	Point<T, N> operator*=(const Point<T, N> &other);
	/**
	 * Divides the passed in value from each of the dimensions in this Point
	 * This function modifies the values in this Point.
	 *
	 * @param val the divisor
	 */
	Point<T, N> operator/=(const T &val);
	/**
	 * Divides the component values of the passed in Point from this Point's components
	 * This function modifies the values in this Point.
	 *
	 * @param other the Point whose components to be divisors
	 */
	Point<T, N> operator/=(const Point<T, N> &other);
};

template<class T, int N>
Point<T, N>::Point(const T val) {
	for (int i = 0; i < N; i++) {
		this->values[i] = val;
	}
}

template<class T, int N>
Point<T, N>::Point(const T other[N]) {
	memcpy(this->values, other, N * sizeof(T) );
}

template<class T, int N>
Point<T, N>::Point(const Point<T, N> &other) {
	memcpy(this->values, other.values, N * sizeof(T) );
}

template<class T, int N>
Point<T, N>::~Point() {
}

template<class T, int N>
bool Point<T, N>::operator==(const Point<T, N> &other) const {
	for (int i = 0; i < N; i++) {
		if (this->values[i] != other.values[i]) {
			return false;
		}
	}
	return true;
}

template<class T, int N>
bool Point<T, N>::operator!=(const Point<T, N> &other) const {
	return !(this == other);
}

// === Operations that do not modify state === //

template<class T, int N>
Point<T, N> Point<T, N>::operator+(const T &val) const {
	Point<T, N> result(*this);
	for (int i = 0; i < N; i++) {
		result.values[i] += val;
	}
	return result;
}

template<class T, int N>
Point<T, N> Point<T, N>::operator+(const Point<T, N> &other) const {
	Point<T, N> result(*this);
	for (int i = 0; i < N; i++) {
		result.values[i] += other.values[i];
	}
	return result;
}

template<class T, int N>
Point<T, N> Point<T, N>::operator-(const T &val) const {
	Point<T, N> result(*this);
	for (int i = 0; i < N; i++) {
		result.values[i] -= val;
	}
	return result;
}

template<class T, int N>
Point<T, N> Point<T, N>::operator-(const Point<T, N> &other) const {
	Point<T, N> result(*this);
	for (int i = 0; i < N; i++) {
		result.values[i] -= other.values[i];
	}
	return result;
}

template<class T, int N>
Point<T, N> Point<T, N>::operator*(const T &val) const {
	Point<T, N> result(*this);
	for (int i = 0; i < N; i++) {
		result.values[i] *= val;
	}
	return result;
}

template<class T, int N>
Point<T, N> Point<T, N>::operator*(const Point<T, N> &other) const {
	Point<T, N> result(*this);
	for (int i = 0; i < N; i++) {
		result.values[i] *= other.values[i];
	}
	return result;
}

template<class T, int N>
Point<T, N> Point<T, N>::operator/(const T &val) const {
	Point<T, N> result(*this);
	for (int i = 0; i < N; i++) {
		result.values[i] /= val;
	}
	return result;
}

template<class T, int N>
Point<T, N> Point<T, N>::operator/(const Point<T, N> &other) const {
	Point<T, N> result(*this);
	for (int i = 0; i < N; i++) {
		result.values[i] /= other.values[i];
	}
	return result;
}

// === Operations that modify state === //

template<class T, int N>
Point<T, N> Point<T, N>::operator+=(const T &val) {
	for (int i = 0; i < N; i++) {
		this->values[i] += val;
	}
	return (*this);
}

template<class T, int N>
Point<T, N> Point<T, N>::operator+=(const Point<T, N> &other) {
	for (int i = 0; i < N; i++) {
		this->values[i] += other.values[i];
	}
	return (*this);
}

template<class T, int N>
Point<T, N> Point<T, N>::operator-=(const T &val) {
	for (int i = 0; i < N; i++) {
		this->values[i] -= val;
	}
	return (*this);
}

template<class T, int N>
Point<T, N> Point<T, N>::operator-=(const Point<T, N> &other) {
	for (int i = 0; i < N; i++) {
		this->values[i] -= other.values[i];
	}
	return (*this);
}

template<class T, int N>
Point<T, N> Point<T, N>::operator*=(const T &val) {
	for (int i = 0; i < N; i++) {
		this->values[i] *= val;
	}
	return (*this);
}

template<class T, int N>
Point<T, N> Point<T, N>::operator*=(const Point<T, N> &other) {
	for (int i = 0; i < N; i++) {
		this->values[i] *= other.values[i];
	}
	return (*this);
}

template<class T, int N>
Point<T, N> Point<T, N>::operator/=(const T &val) {
	for (int i = 0; i < N; i++) {
		this->values[i] /= val;
	}
	return (*this);
}

template<class T, int N>
Point<T, N> Point<T, N>::operator/=(const Point<T, N> &other) {
	for (int i = 0; i < N; i++) {
		this->values[i] /= other.values[i];
	}
	return (*this);
}

} /* namespace math */
} /* namespace sl */

#endif /* __SL_MATH__POINT_HPP */
