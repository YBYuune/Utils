#ifndef __BITMASKHELPERS_H__
#define __BITMASKHELPERS_H__

namespace YBMath
{
	namespace Helpers
	{
		class BitMaskHelpers
		{
		public:
			template <typename T>
			static void RemoveFlagsFromMask(T& mask, const T flags);

		};






		//////////// ---- IMPLEMENTATION ----
		template <typename T>
		inline void BitMaskHelpers::RemoveFlagsFromMask(T& mask, const T flags)
		{
			mask &= ~flags;
		}
	}
}


#endif