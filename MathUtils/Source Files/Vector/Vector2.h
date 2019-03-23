#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include "Point\Point2f.h"

namespace YBMath
{
    class Vector2
    {
	////      ---- MEMBER FUNCTIONS ----
    public:
        Vector2();
        Vector2(float x);
        Vector2(float x, float y);
		Vector2(const Vector2& v);
        ~Vector2();

		// Getters and Setters
		void SetXY(float x, float y);

		float GetX() const;
		void SetX(float x);

		float GetY() const;
		void SetY(float y);

		// Logically const because it does not affect x, y components
		float GetMagnitudeSquared() const;
		float GetMagnitude() const;
		const Vector2 GetNormalized() const;
		const Vector2& Normalize();

	private:
		Vector2(const Point2f &p);

		template<typename T>
		void SetMemberIntegrityCheck(T& member, const T &value);


	////      ---- STATIC FUNCTIONS ----
	public:
		static float GetMagnitude(const Vector2 &v);
		static float GetMagnitudeSquared(const Vector2 &v);
		static const Vector2 GetNormalized(const Vector2& v);

	
	////      ---- CONST VARIABLES ----
	private:
		// BASE FLAGS
		const unsigned char c_CLEAN			= 0b0000'0000;
		const unsigned char c_MAGSQR_DIRTY  = 0b0000'0001;
		const unsigned char c_MAG_DIRTY		= 0b0000'0010;
		const unsigned char c_NORM_DIRTY	= 0b0000'0100;

		// COMBO FLAGS
		const unsigned char c_ALL_DIRTY		= c_MAGSQR_DIRTY | c_MAG_DIRTY | c_NORM_DIRTY;

    
	////      ---- MEMBER VARIABLES ----
	private:
		// Values that will be accessible outside the class
		float m_X;
		float m_Y;

		// Cached members that only change when X, Y components are changed
		mutable float   m_MagnitudeSquared;
		mutable float   m_Magnitude;
		mutable Point2f m_Normalized;

		// Variable for state of object
		mutable unsigned char m_DirtynessMask;
    };
}



#endif