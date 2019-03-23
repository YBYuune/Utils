#include "stdafx.h"
#include "CppUnitTest.h"

#include "Vector/Vector2.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBMath;

namespace Vector2Tests
{	
	TEST_CLASS(Vector2_Construction)
	{
		TEST_METHOD(CreateVector2_ZeroParam)
		{
			Logger::WriteMessage("IN: CreateVector2_ZeroParam");
			YBMath::Vector2 testVec;

			Assert::AreEqual(0.0f, testVec.GetX());
			Assert::AreEqual(0.0f, testVec.GetY());
		}

		TEST_METHOD(CreateVector2_OneParam)
		{
			Logger::WriteMessage("IN: CreateVector2_OneParam");

			const float xyValue = 5.5f;

			YBMath::Vector2 testVec(xyValue);

			Assert::AreEqual(xyValue, testVec.GetX());
			Assert::AreEqual(xyValue, testVec.GetY());
		}


		TEST_METHOD(CreateVector2_TwoParam)
		{
			Logger::WriteMessage("IN: CreateVector2_TwoParam");

			const float xValue = 5.5f;
			const float yValue = -4.3f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(xValue, testVec.GetX());
			Assert::AreEqual(yValue, testVec.GetY());
		}
	};

	TEST_CLASS(Vector2_Setters)
	{
		TEST_METHOD(Vector2_SetX)
		{
			Logger::WriteMessage("IN: Vector2_SetX");

			const float xValue = 5.5f;

			YBMath::Vector2 testVec;

			// TEST
			testVec.SetX(xValue);

			// VALIDATION
			Assert::AreEqual(xValue, testVec.GetX());
		}


		TEST_METHOD(Vector2_SetY)
		{
			Logger::WriteMessage("IN: CreateVector2_TwoParam");

			const float yValue = -4.3f;

			YBMath::Vector2 testVec;

			// TEST
			testVec.SetY(yValue);

			// VALIDATION
			Assert::AreEqual(yValue, testVec.GetY());
		}


		TEST_METHOD(Vector2_SetXY)
		{
			Logger::WriteMessage("IN: CreateVector2_TwoParam");

			const float xValue = 5.5f;
			const float yValue = -4.3f;

			YBMath::Vector2 testVec;

			// TEST
			testVec.SetXY(xValue, yValue);

			// VALIDATION
			Assert::AreEqual(xValue, testVec.GetX());
			Assert::AreEqual(yValue, testVec.GetY());
		}
	};

	TEST_CLASS(Vector2_CachedMembers)
	{
		TEST_METHOD(Vector2_MagnitudeSquared)
		{
			Logger::WriteMessage("IN: Vector2_MagnitudeSquared");

			const float xValue = 3.0f;
			const float yValue = 4.0f;
			const float magnitudeSquared = 25.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(magnitudeSquared, testVec.GetMagnitudeSquared());
		}

		TEST_METHOD(Vector2_MagnitudeSquaredAfterSet)
		{
			Logger::WriteMessage("IN: Vector2_MagnitudeSquared");

			const float xValue = 3.0f;
			const float yValue = 4.0f;
			const float magnitudeSquared = 25.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(magnitudeSquared, testVec.GetMagnitudeSquared());
		}


		TEST_METHOD(Vector2_MagnitudeSquared_XYEqualZero)
		{
			Logger::WriteMessage("IN: Vector2_MagnitudeSquared_XYEqualZero");

			const float xValue = 0.0f;
			const float yValue = 0.0f;
			const float magnitudeSquared = 0.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(magnitudeSquared, testVec.GetMagnitudeSquared());
		}


		TEST_METHOD(Vector2_Magnitude)
		{
			Logger::WriteMessage("IN: Vector2_Magnitude");

			const float xValue = 3.0f;
			const float yValue = 4.0f;
			const float magnitude = 5.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(magnitude, testVec.GetMagnitude());
		}

		TEST_METHOD(Vector2_MagnitudeZero)
		{
			Logger::WriteMessage("IN: Vector2_MagnitudeZero");

			const float magnitude = 0.0f;

			YBMath::Vector2 testVec;

			Assert::AreEqual(magnitude, testVec.GetMagnitude());
		}


		TEST_METHOD(Vector2_NormalizeWithXYEqualZero)
		{
			Logger::WriteMessage("IN: Vector2_NormalizeWithXYEqualZero");

			YBMath::Vector2 testVec;
			YBMath::Vector2 normalizedVec;

			testVec.Normalize();

			Assert::AreEqual(normalizedVec.GetX(), testVec.GetX());
			Assert::AreEqual(normalizedVec.GetY(), testVec.GetY());
		}


		TEST_METHOD(Vector2_CheckNormalized)
		{
			Logger::WriteMessage("IN: Vector2_CheckNormalized");

			const float magnitude = 5.0f;
			const float xComp = 3.0f;
			const float yComp = 4.0f;
			const float normalizedXComp = xComp / magnitude;
			const float normalizedYComp = yComp / magnitude;

			YBMath::Vector2 testVec(xComp, yComp);

			YBMath::Vector2 normalizedTestVec = testVec.GetNormalized();

			Assert::AreEqual(normalizedXComp, normalizedTestVec.GetX());
			Assert::AreEqual(normalizedYComp, normalizedTestVec.GetY());
		}

		TEST_METHOD(Vector2_GetNormalizedEnsureNoChangeToOriginal)
		{
			Logger::WriteMessage("IN: Vector2_GetNormalizedEnsureNoChangeToOriginal");

			const float magnitude = 5.0f;
			const float xComp = 3.0f;
			const float yComp = 4.0f;
			const float normalizedXComp = xComp / magnitude;
			const float normalizedYComp = yComp / magnitude;

			YBMath::Vector2 testVec(xComp, yComp);

			testVec.GetNormalized();

			Assert::AreEqual(xComp, testVec.GetX());
			Assert::AreEqual(yComp, testVec.GetY());
		}


		TEST_METHOD(Vector2_NormalizedMagnitude)
		{
			Logger::WriteMessage("IN: Vector2_NormalizeWithMagnitudeZero");

			const float magnitude = 1.0f;
			const float xComp = 3.0f;
			const float yComp = 4.0f;

			YBMath::Vector2 testVec(xComp, yComp);

			testVec.Normalize();

			Assert::AreEqual(magnitude, testVec.GetMagnitude());
		}
	};

	TEST_CLASS(Vector2_Static)
	{
		TEST_METHOD(Vector2_StaticGetMagnitudeSquared)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetMagnitudeSquared");

			const float xValue = 3.0f;
			const float yValue = 4.0f;
			const float magnitudeSquared = 25.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(magnitudeSquared, YBMath::Vector2::GetMagnitudeSquared(testVec));
		}


		TEST_METHOD(Vector2_StaticGetMagnitudeSquaredZero)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetMagnitudeSquaredZero");

			const float xValue = 0.0f;
			const float yValue = 0.0f;
			const float magnitudeSquared = 0.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(magnitudeSquared, YBMath::Vector2::GetMagnitudeSquared(testVec));
		}


		TEST_METHOD(Vector2_StaticGetMagnitudeSquaredIsNonNegative)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetMagnitudeSquaredIsNonNegative");

			const float xValue = -10.0f;
			const float yValue = -10.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::IsTrue(YBMath::Vector2::GetMagnitudeSquared(testVec) >= 0.0f);
		}


		TEST_METHOD(Vector2_StaticGetMagnitudeSquaredDoesNotAlterOriginal)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetMagnitudeSquaredDoesNotAlterOriginal");

			const float xValue = 1.0f;
			const float yValue = -5.0f;

			YBMath::Vector2 testVec(xValue, yValue);
			YBMath::Vector2::GetMagnitudeSquared(testVec);


			Assert::AreEqual(xValue, testVec.GetX());
			Assert::AreEqual(yValue, testVec.GetY());
		}


		TEST_METHOD(Vector2_StaticGetMagnitude)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetMagnitude");

			const float xValue = 3.0f;
			const float yValue = 4.0f;
			const float magnitude = 5.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(magnitude, YBMath::Vector2::GetMagnitude(testVec));
		}


		TEST_METHOD(Vector2_StaticGetMagnitudeZero)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetMagnitudeZero");

			const float xValue = 0.0f;
			const float yValue = 0.0f;
			const float magnitude = 0.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::AreEqual(magnitude, YBMath::Vector2::GetMagnitude(testVec));
		}


		TEST_METHOD(Vector2_StaticGetMagnitudeIsNonZero)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetMagnitudeIsNonZero");

			const float xValue = -50.0f;
			const float yValue = 4.0f;

			YBMath::Vector2 testVec(xValue, yValue);

			Assert::IsTrue(YBMath::Vector2::GetMagnitude(testVec) >= 0.0f);
		}


		TEST_METHOD(Vector2_StaticGetMagnitudeDoesNotAlterOriginal)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetMagnitudeDoesNotAlterOriginal");

			const float xValue = 6.0f;
			const float yValue = -31.5f;

			YBMath::Vector2 testVec(xValue, yValue);

			YBMath::Vector2::GetMagnitude(testVec);

			Assert::AreEqual(xValue, testVec.GetX());
			Assert::AreEqual(yValue, testVec.GetY());
		}


		TEST_METHOD(Vector2_StaticGetNormalized)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetNormalized");

			YBMath::Vector2 testVec;
			YBMath::Vector2 normalizedVec = Vector2::GetNormalized(testVec);

			Assert::AreEqual(normalizedVec.GetX(), testVec.GetX());
			Assert::AreEqual(normalizedVec.GetY(), testVec.GetY());
		}


		TEST_METHOD(Vector2_StaticGetNormalizedXYLessThanZero)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetNormalizedXYLessThanZero");

			const float xComp = 0.3f;
			const float yComp = 0.4f;
			const float xCompNormalized = 0.6f;
			const float yCompNormalized = 0.8f;

			YBMath::Vector2 testVec(xComp, yComp);
			YBMath::Vector2 normalizedVec = Vector2::GetNormalized(testVec);


			Assert::AreEqual(xCompNormalized, normalizedVec.GetX());
			Assert::AreEqual(yCompNormalized, normalizedVec.GetY());
		}


		TEST_METHOD(Vector2_StaticGetNormalizedXYLessThanZeroMagnitudeOne)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetNormalizedXYLessThanZeroMagnitudeOne");

			const float xComp = 0.3f;
			const float yComp = 0.4f;
			const float xCompNormalized = 0.6f;
			const float yCompNormalized = 0.8f;
			const float magnitude = 1.0f;

			YBMath::Vector2 testVec(xComp, yComp);
			YBMath::Vector2 normalizedVec = Vector2::GetNormalized(testVec);


			Assert::AreEqual(magnitude, normalizedVec.GetMagnitude());
		}


		TEST_METHOD(Vector2_StaticGetNormalizedMagnitudeSquaredOne)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetNormalizedMagnitudeSquaredOne");

			const float xComp = -4.0f;
			const float yComp = -0.4f;
			const float magnitudeSquared = 1.0f;

			YBMath::Vector2 testVec(xComp, yComp);
			YBMath::Vector2 normalizedVec = Vector2::GetNormalized(testVec);

			Assert::AreEqual(magnitudeSquared, normalizedVec.GetMagnitudeSquared());
		}


		TEST_METHOD(Vector2_StaticGetNormalizedMagnitudeOne)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetNormalizedMagnitudeOne");

			const float xComp = 3.0f;
			const float yComp = 4.0f;
			const float magnitude = 1.0f;

			YBMath::Vector2 testVec(xComp, yComp);
			YBMath::Vector2 normalizedVec = Vector2::GetNormalized(testVec);

			Assert::AreEqual(magnitude, normalizedVec.GetMagnitude());
		}


		TEST_METHOD(Vector2_StaticGetNormalizedDoesNotAlterOriginal)
		{
			Logger::WriteMessage("IN: Vector2_StaticGetNormalizedDoesNotAlterOriginal");

			const float xComp = -0.3f;
			const float yComp = 555.0f;
			const float magnitude = 1.0f;

			YBMath::Vector2 testVec(xComp, yComp);
			YBMath::Vector2 normalizedVec = Vector2::GetNormalized(testVec);

			Assert::AreEqual(xComp, testVec.GetX());
			Assert::AreEqual(yComp, testVec.GetY());
		}
	};

	TEST_CLASS(Vector2_Combo)
	{
		TEST_METHOD(Vector2_GetMagnitudeSquaredTwice)
		{
			Logger::WriteMessage("IN: Vector2_GetMagnitudeSquaredTwice");

			const float xComp = 3.0f;
			const float yComp = 4.0f;
			const float magnitudeSquared = 25.0f;

			Vector2 testVec(xComp, yComp);

			Assert::AreEqual(magnitudeSquared, testVec.GetMagnitudeSquared());

			Assert::AreEqual(magnitudeSquared, testVec.GetMagnitudeSquared());
		}
	};

	TEST_CLASS(Vector2_UnaryOperators)
	{
		TEST_METHOD(Vector2_Negation)
		{
			Logger::WriteMessage("IN: Vector2_Negation");

			const float xComp = 1.0f;
			const float yComp = -5.0f;
			const float negatedXComp = -xComp;
			const float negatedYComp = -yComp;


			Vector2 startVec(xComp, yComp);

			Vector2 negatedVec = -startVec;

			Assert::AreEqual(negatedVec.GetX(), negatedXComp);
			Assert::AreEqual(negatedVec.GetY(), negatedYComp);
		}
	};

	TEST_CLASS(Vector2_BinaryComparisonOperators)
	{
		TEST_METHOD(Vector2_Equals)
		{
			Logger::WriteMessage("IN: Vector2_Equals");

			const float xComp = 1.0f;
			const float yComp = -5.0f;

			Vector2 testVec1(xComp, yComp);
			Vector2 testVec2(xComp, yComp);

			Assert::IsTrue(testVec1 == testVec2);
		}

		TEST_METHOD(Vector2_EqualsFalse)
		{
			Logger::WriteMessage("IN: Vector2_EqualsFalse");

			const float xComp1 = 1.0f;
			const float yComp1 = -5.0f;
			const float xComp2 = -99.0f;
			const float yComp2 = 12.34f;

			Vector2 testVec1(xComp1, yComp1);
			Vector2 testVec2(xComp2, yComp2);

			Assert::IsFalse(testVec1 == testVec2);
		}


		TEST_METHOD(Vector2_NotEquals)
		{
			Logger::WriteMessage("IN: Vector2_NotEquals");

			const float xComp1 = 1.0f;
			const float yComp1 = -5.0f;
			const float xComp2 = -99.0f;
			const float yComp2 = 12.34f;

			Vector2 testVec1(xComp1, yComp1);
			Vector2 testVec2(xComp2, yComp2);

			Assert::IsTrue(testVec1 != testVec2);
		}

		TEST_METHOD(Vector2_NotEqualsFalse)
		{
			Logger::WriteMessage("IN: Vector2_NotEqualsFalse");

			const float xComp = 1.0f;
			const float yComp = -5.0f;

			Vector2 testVec1(xComp, yComp);
			Vector2 testVec2(xComp, yComp);

			Assert::IsFalse(testVec1 != testVec2);
		}
	};

}