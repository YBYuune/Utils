#ifndef __MATHHELPERS_H__
#define __MATHHELPERS_H__

#include <cmath>

namespace YBMath
{
	namespace Helpers
	{
		//////////// ---- DEFINITION ----
		class MathHelpers
		{
		public:
			static const float FEPSILON;

			static bool cmpf(const float lh, const float rh, const float epsilon = FEPSILON);

		};



		//////////// ---- IMPLEMENTATION ----
		inline bool MathHelpers::cmpf(const float lh, const float rh, const float epsilon)
		{
			return std::fabs(lh - rh) < epsilon;
		}
	}
}

#endif