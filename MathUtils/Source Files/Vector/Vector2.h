#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include "Point/Point2f.h"
#include "Helpers/MathHelpers.h"

namespace YBMath
{
	//////////// ---- DEFINITION ----
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
		Vector2 GetNormalized() const;
		const Vector2& Normalize();

	private:
		Vector2(const Point2f &p);

		template<typename T>
		void SetMemberIntegrityCheck(T& member, const T &value);


	////      ---- STATIC FUNCTIONS ----
	public:
		static float GetMagnitude(const Vector2 &v);
		static float GetMagnitudeSquared(const Vector2 &v);
		static Vector2 GetNormalized(const Vector2& v);

	
	////      ---- STATIC CONST VARIABLES ----
	private:
		// BASE FLAGS
		static const unsigned char c_CLEAN			= 0b0000'0000;
		static const unsigned char c_MAGSQR_DIRTY	= 0b0000'0001;
		static const unsigned char c_MAG_DIRTY		= 0b0000'0010;
		static const unsigned char c_NORM_DIRTY		= 0b0000'0100;

		// COMBO FLAGS
		static const unsigned char c_ALL_DIRTY		= c_MAGSQR_DIRTY | c_MAG_DIRTY | c_NORM_DIRTY;


	////      ---- OPERATOR OVERLOADS ----
	public:
		bool operator == (const Vector2& o) const;
		bool operator != (const Vector2& o) const;

		Vector2 operator - () const;

		// float-based operations
		Vector2 operator * (const float o) const;
		Vector2 operator / (const float o) const;
		Vector2 operator + (const float o) const;
		Vector2 operator - (const float o) const;
		friend Vector2 operator * (const float lh, const Vector2& rh);
		friend Vector2 operator / (const float lh, const Vector2& rh);
		friend Vector2 operator + (const float lh, const Vector2& rh);
		friend Vector2 operator - (const float lh, const Vector2& rh);

		// Component-wise operations
		Vector2 operator * (const Vector2& o) const;
		Vector2 operator / (const Vector2& o) const;
		Vector2 operator + (const Vector2& o) const;
		Vector2 operator - (const Vector2& o) const;

		Vector2& operator *= (const float o);
		Vector2& operator /= (const float o);
		Vector2& operator += (const float o);
		Vector2& operator -= (const float o);

		// Component-wise operations
		Vector2& operator *= (const Vector2& o);
		Vector2& operator /= (const Vector2& o);
		Vector2& operator += (const Vector2& o);
		Vector2& operator -= (const Vector2& o);

    
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





	//////////// ---- IMPLEMENTATION ----
	inline bool Vector2::operator == (const Vector2& o) const
	{
		return Helpers::MathHelpers::cmpf(m_X, o.m_X) && Helpers::MathHelpers::cmpf(m_Y, o.m_Y);
	}

	inline bool Vector2::operator != (const Vector2& o) const
	{
		return !Helpers::MathHelpers::cmpf(m_X, o.m_X) || !Helpers::MathHelpers::cmpf(m_Y, o.m_Y);
	}

	inline Vector2 Vector2::operator - () const
	{
		return Vector2(-m_X, -m_Y);
	}




	inline Vector2 Vector2::operator + (const float o) const
	{
		return Vector2(m_X + o, m_Y + o);
	}

	inline Vector2 Vector2::operator - (const float o) const
	{
		return Vector2(m_X - o, m_Y - o);
	}

	inline Vector2 Vector2::operator * (const float o) const
	{
		return Vector2(m_X * o, m_Y * o);
	}

	inline Vector2 Vector2::operator / (const float o) const
	{
		return Vector2(m_X / o, m_Y / o);
	}




	inline Vector2 YBMath::operator + (const float lh, const Vector2& rh)
	{
		return Vector2(lh + rh.m_X, lh + rh.m_Y);
	}

	inline Vector2 YBMath::operator - (const float lh, const Vector2& rh)
	{
		return Vector2(lh - rh.m_X, lh - rh.m_Y);
	}

	inline Vector2 YBMath::operator * (const float lh, const Vector2& rh)
	{
		return Vector2(lh * rh.m_X, lh * rh.m_Y);
	}

	inline Vector2 YBMath::operator / (const float lh, const Vector2& rh)
	{
		return Vector2(lh / rh.m_X, lh / rh.m_Y);
	}




	inline Vector2 Vector2::operator + (const Vector2& o) const
	{
		return Vector2(m_X + o.m_X, m_Y + o.m_Y);
	}

	inline Vector2 Vector2::operator - (const Vector2& o) const
	{
		return Vector2(m_X - o.m_X, m_Y - o.m_Y);
	}

	inline Vector2 Vector2::operator * (const Vector2& o) const
	{
		return Vector2(m_X * o.m_X, m_Y * o.m_Y);
	}

	inline Vector2 Vector2::operator / (const Vector2& o) const
	{
		return Vector2(m_X / o.m_X, m_Y / o.m_Y);
	}




	inline Vector2& Vector2::operator += (const float o)
	{
		SetXY(m_X + o, m_Y + o);
		return *this;
	}

	inline Vector2& Vector2::operator -= (const float o)
	{
		SetXY(m_X - o, m_Y - o);
		return *this;
	}

	inline Vector2& Vector2::operator *= (const float o)
	{
		SetXY(m_X * o, m_Y * o);
		return *this;
	}

	inline Vector2& Vector2::operator /= (const float o)
	{
		SetXY(m_X / o, m_Y / o);
		return *this;
	}




	inline Vector2& Vector2::operator += (const Vector2& o)
	{
		SetXY(m_X + o.m_X, m_Y + o.m_Y);
		return *this;
	}

	inline Vector2& Vector2::operator -= (const Vector2& o)
	{
		SetXY(m_X - o.m_X, m_Y - o.m_Y);
		return *this;
	}

	inline Vector2& Vector2::operator *= (const Vector2& o)
	{
		SetXY(m_X * o.m_X, m_Y * o.m_Y);
		return *this;
	}

	inline Vector2& Vector2::operator /= (const Vector2& o)
	{
		SetXY(m_X / o.m_X, m_Y / o.m_Y);
		return *this;
	}
}



#endif