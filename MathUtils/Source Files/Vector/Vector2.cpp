#include "Vector2.h"

#include <cmath>

using namespace YBMath;

/// 
float Vector2::GetMagnitude(const Vector2 &v)
{
	return std::sqrtf( (v.m_X * v.m_X) + (v.m_Y * v.m_Y) );
}

/// Compare values of two variables
template <typename T>
bool Vector2::WillMakeDirty(const T &original, const T &value)
{
	return original != value;
}


Vector2::Vector2() :
	m_X(0.0f),
	m_Y(0.0f),
	m_Magnitude(0.0f),
	m_IsDirty(true)
{
}

Vector2::Vector2(float x) :
	m_X(x), 
	m_Y(x),
	m_Magnitude(0.0f),
	m_IsDirty(true)
{
}

Vector2::Vector2(float x, float y) :
	m_X(x), 
	m_Y(y),
	m_Magnitude(0.0f),
	m_IsDirty(true)
{
}

Vector2::~Vector2()
{
}


void Vector2::SetXY(float x, float y)
{
	SetX(x);
	SetY(y);
}

// X Member Getter and Setter
float Vector2::GetX() const
{
	return m_X;
}

void Vector2::SetX(float x)
{
	SetMemberIntegrityCheck(m_X, x);
}


// Y Member Getter and Setter
float Vector2::GetY() const
{
	return m_Y;
}

void Vector2::SetY(float y)
{
	SetMemberIntegrityCheck(m_Y, y);
}


// Calculate Magnitude if Vector2 is dirty
float Vector2::GetMagnitude() const
{
	if (m_IsDirty)
		m_Magnitude = Vector2::GetMagnitude(*this);

	return m_Magnitude;
}

// For use when setting member variables that change integrity of object
// Let's us know that we need to recalculate certain member variables
template<typename T>
void Vector2::SetMemberIntegrityCheck(T& member, const T &value)
{
	// Update dirty-ness flag
	m_IsDirty = WillMakeDirty(member, value);

	member = value;
}