#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\MathUtils\MathUtils\Headers\Vector2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBMath;

namespace UtilsTestingSuite
{		
	TEST_CLASS(Vector2)
	{
	public:
		
		TEST_METHOD(CreateVector2)
		{
            Logger::WriteMessage("IN: CreateVector2");
            YBMath::Vector2 testVec;

            Assert::AreEqual(testVec.x, 0.0f);
            Assert::AreEqual(testVec.y, 0.0f);
		}

	};
}