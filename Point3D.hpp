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

#ifndef __SL_MATH__POINT3D_HPP
#define __SL_MATH__POINT3D_HPP

namespace sl {
namespace math {

#include "Point.hpp"

template<class T>
class Point3D : public sl::math::Point<T, 3> {
public:
	Point3D(T val = 0);
	Point3D(T x, T y, T z);
	Point3D(const Point3D<T> &other);
	virtual ~Point3D();

	T x() const;
	T y() const;
	T z() const;
};

template<class T>
Point3D<T>::Point3D(T val) : sl::math::Point<T, 3>(val) {
}

template<class T>
Point3D<T>::Point3D(T x, T y, T z) {
	this->values[0] = x;
	this->values[1] = y;
	this->values[2] = z;
}

template<class T>
Point3D<T>::Point3D(const Point3D<T> &other) {
	for (int i = 0; i < 3; ++i) {
		this->values[i] = other.values[i];
	}
}

template<class T>
Point3D<T>::~Point3D() {
}

template<class T>
T Point3D<T>::x() const {
	return this->values[0];
}

template<class T>
T Point3D<T>::y() const {
	return this->values[1];
}

template<class T>
T Point3D<T>::z() const {
	return this->values[2];
}

} /* namespace math */
} /* namespace sl */

#endif /* __SL_MATH__POINT3D_HPP */
