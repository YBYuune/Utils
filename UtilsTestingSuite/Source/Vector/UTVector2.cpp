#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vector\Vector2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBMath;

namespace YBMathTestingSuite
{		
	TEST_CLASS(Vector2)
	{
	public:
		TEST_METHOD(CreateVector2_ZeroParam)
		{
            Logger::WriteMessage("IN: CreateVector2_ZeroParam");
            YBMath::Vector2 testVec;

            Assert::AreEqual(testVec.GetX(), 0.0f);
            Assert::AreEqual(testVec.GetY(), 0.0f);
		}

		TEST_METHOD(CreateVector2_OneParam)
		{
			Logger::WriteMessage("IN: CreateVector2_OneParam");

			const float xyValue = 5.5f;

			YBMath::Vector2 testVec(xyValue);

			Assert::AreEqual(testVec.GetX(), xyValue);
			Assert::AreEqual(testVec.GetY(), xyValue);
		}


		TEST_METHOD(CreateVector2_TwoParam)
		{
			Logger::WriteMessage("IN: CreateVector2_TwoParam");

			const float xValue = 5.5f;
			const float yValue = -4.3f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(testVec.GetX(), xValue);
			Assert::AreEqual(testVec.GetY(), yValue);
		}


		TEST_METHOD(Vector2_MagnitudeSquared)
		{
			Logger::WriteMessage("IN: Vector2_MagnitudeSquared");

			const float xValue = 3.0f;
			const float yValue = 4.0f;
			const float magnitudeSquared = 25.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(testVec.GetMagnitudeSquared(), magnitudeSquared);
		}
	};
}