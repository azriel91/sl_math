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

#include <google/gtest/gtest.h>
#include <google/gmock/gmock.h>

#include "../Point3D.hpp"

namespace sl {
namespace math {

using ::sl::math::Point3D;

class Point3DTest : public testing::Test {
protected:
	Point3D<double> one;
	Point3D<double> two;
	Point3D<double> three;
	Point3D<double> even;

	virtual void SetUp() {
		this->one = Point3D<double>(1.0); // 1.0, 1.0, 1.0
		this->two = Point3D<double>(2.0, 2.0, 2.0);
		this->three = Point3D<double>(3.0, 3.0, 3.0);
		this->even = Point3D<double>(2.0, 4.0, 6.0);
	}

	virtual void TearDown() {
	}
};

TEST_F(Point3DTest, defaultsToZeroForAllDimensions) {
	Point3D<double> zero;
	EXPECT_EQ(0.0, zero.x());
	EXPECT_EQ(0.0, zero.y());
	EXPECT_EQ(0.0, zero.z());
}

TEST_F(Point3DTest, operatorEqualsTest) {
	EXPECT_EQ(Point3D<double>(1.0, 1.0, 1.0), this->one);
	EXPECT_EQ(Point3D<double>(2.0, 4.0, 6.0), this->even);
}

TEST_F(Point3DTest, additionTest) {
	EXPECT_EQ(Point3D<double>(3.0, 3.0, 3.0), this->one + this->two);
}

TEST_F(Point3DTest, additionChainTest) {
	EXPECT_EQ(Point3D<double>(6.0, 6.0, 6.0), this->one + this->two + this->three);
}

TEST_F(Point3DTest, subtractionTest) {
	EXPECT_EQ(Point3D<double>(1.0, 1.0, 1.0), this->two - this->one);
}

TEST_F(Point3DTest, subtractionChainTest) {
	EXPECT_EQ(Point3D<double>(0.0, 0.0, 0.0), this->three - this->one - this->two);
}

TEST_F(Point3DTest, multiplicationTest) {
	EXPECT_EQ(Point3D<double>(6.0, 6.0, 6.0), this->two * this->three);
}

TEST_F(Point3DTest, multiplicationChainTest) {
	EXPECT_EQ(Point3D<double>(12.0, 24.0, 36.0), this->two * this->three * this->even);
}

TEST_F(Point3DTest, divisionTest) {
	EXPECT_EQ(Point3D<double>(1.0, 2.0, 3.0), this->even / this->two);
}

TEST_F(Point3DTest, divisionChainTest) {
	EXPECT_EQ(Point3D<double>(0.5, 1.0, 1.5), this->even / this->two / this->two);
}

TEST_F(Point3DTest, mutatingAdditionTest) {
	Point3D<double> point(1, 2, 3);
	point += Point3D<double>(2, 1, 0);

	EXPECT_EQ(Point3D<double>(3, 3, 3), point);
}

TEST_F(Point3DTest, mutatingSubtractionTest) {
	Point3D<double> point(2, 1, 0);
	point -= Point3D<double>(3, 2, 1);

	EXPECT_EQ(Point3D<double>(-1, -1, -1), point);
}

TEST_F(Point3DTest, mutatingMultiplicationTest) {
	Point3D<double> point(1, 2, 3);
	point *= point;

	EXPECT_EQ(Point3D<double>(1, 4, 9), point);
}

TEST_F(Point3DTest, mutatingDivisionTest) {
	Point3D<double> point(6, 4, 2);
	point /= this->two;

	EXPECT_EQ(Point3D<double>(3, 2, 1), point);
}

TEST_F(Point3DTest, operatorOrderTest) {
	EXPECT_EQ(Point3D<double>(7, 7, 7), this->one + this->two * this->three);
}

} /* namespace math */
} /* namespace sl */

int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
