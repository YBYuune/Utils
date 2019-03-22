#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vector\Vector2.h"

#include <string>

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

        TEST_METHOD(Vector2_MagnitudeZero)
        {
            Logger::WriteMessage("IN: Vector2_MagnitudeZero");

            const float magnitude = 0.0f;

            YBMath::Vector2 testVec;

            Assert::AreEqual(testVec.GetMagnitude(), magnitude);
        }


        TEST_METHOD(Vector2_NormalizeWithXYEqualZero)
        {
            Logger::WriteMessage("IN: Vector2_NormalizeWithMagnitudeZero");

            YBMath::Vector2 testVec;
            YBMath::Vector2 normalizedVec;
            
            testVec.Normalize();

            Assert::AreEqual(testVec.GetX(), normalizedVec.GetX());
            Assert::AreEqual(testVec.GetY(), normalizedVec.GetY());
        }


        TEST_METHOD(Vector2_CheckNormalized)
        {
            Logger::WriteMessage("IN: Vector2_NormalizeWithMagnitudeZero");

            const float xComp = 3.0f / 5.0f;
            const float yComp = 4.0f / 5.0f;

            Logger::WriteMessage((std::string("XCOMP: ") + std::to_string(xComp)).c_str());
            Logger::WriteMessage((std::string("YCOMP: ") + std::to_string(yComp)).c_str());

            YBMath::Vector2 testVec(3.0f, 4.0f);

            YBMath::Vector2 normalizedTestVec = testVec.GetNormalized();

            Assert::AreEqual(normalizedTestVec.GetX(), xComp);
            Assert::AreEqual(normalizedTestVec.GetY(), yComp);
        }


        TEST_METHOD(Vector2_NormalizedMagnitude)
        {
            Logger::WriteMessage("IN: Vector2_NormalizeWithMagnitudeZero");

            const float magnitude = 1.0f;

            YBMath::Vector2 testVec(3.0f, 4.0f);

            testVec.Normalize();

            Assert::AreEqual(testVec.GetMagnitude(), magnitude);
        }


	};
}