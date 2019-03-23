#include "Vector2.h"
#include "Helpers/BitMaskHelpers.h"

#include <cmath>


using namespace YBMath;

/// 
float Vector2::GetMagnitude(const Vector2 &v)
{
	return std::sqrt( GetMagnitudeSquared(v) );
}

float Vector2::GetMagnitudeSquared(const Vector2 &v)
{
	return v.GetMagnitudeSquared();
}

const Vector2 Vector2::GetNormalized(const Vector2& v)
{
	// Create vector to store normalized values
	Vector2 normalized = v;

	normalized.Normalize();

	return normalized;
}



Vector2::Vector2() :
	m_X(0.0f),
	m_Y(0.0f),
	m_MagnitudeSquared(0.0f),
	m_Magnitude(0.0f),
	m_Normalized( { 0.0f, 0.0f } ),
	m_DirtynessMask(c_ALL_DIRTY)
{
}

Vector2::Vector2(float x) :
	m_X(x), 
	m_Y(x),
	m_MagnitudeSquared(0.0f),
	m_Magnitude(0.0f),
	m_Normalized( { 0.0f, 0.0f } ),
	m_DirtynessMask(c_ALL_DIRTY)
{
}

Vector2::Vector2(float x, float y) :
	m_X(x), 
	m_Y(y),
	m_MagnitudeSquared(0.0f),
	m_Magnitude(0.0f),
	m_Normalized( { 0.0f, 0.0f } ),
	m_DirtynessMask(c_ALL_DIRTY)
{
}

Vector2::Vector2(const Vector2& v) :
	m_X(v.m_X),
	m_Y(v.m_Y),
	m_MagnitudeSquared(v.m_MagnitudeSquared),
	m_Magnitude(v.m_Magnitude),
	m_Normalized(v.m_Normalized),
	m_DirtynessMask(v.m_DirtynessMask)
{
}

Vector2::Vector2(const Point2f& p) :
	m_X(p.x),
	m_Y(p.y),
	m_MagnitudeSquared(0.0f),
	m_Magnitude(0.0f),
	m_Normalized( { 0.0f, 0.0f } ),
	m_DirtynessMask(c_ALL_DIRTY)
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


float Vector2::GetMagnitudeSquared() const
{
	// Re-calculate magnitude squared if it is dirty
	if (m_DirtynessMask & c_MAGSQR_DIRTY)
	{
		// calculate square of magnitude
		m_MagnitudeSquared = (m_X * m_X) + (m_Y * m_Y);

		Helpers::BitMaskHelpers::RemoveFlagsFromMask(m_DirtynessMask, c_MAGSQR_DIRTY);
	}

	return m_MagnitudeSquared;
}

// Calculate Magnitude if Vector2 is dirty
float Vector2::GetMagnitude() const
{
	// Re-calculate magnitude if it needs to be recalculated
	if (m_DirtynessMask & c_MAG_DIRTY)
	{
		m_Magnitude = std::sqrt( GetMagnitudeSquared() );

		Helpers::BitMaskHelpers::RemoveFlagsFromMask(m_DirtynessMask, c_MAG_DIRTY);
	}

	return m_Magnitude;
}


const Vector2 Vector2::GetNormalized() const
{
	// Check if we need to recalculate
	if (m_DirtynessMask & c_NORM_DIRTY)
	{
		// Call static normalization function
		Vector2 normalized = GetNormalized(*this);

		// Store component values in our local normal member
		m_Normalized.x = normalized.GetX();
		m_Normalized.y = normalized.GetY();

		// Clean normal flag
		Helpers::BitMaskHelpers::RemoveFlagsFromMask(m_DirtynessMask, c_NORM_DIRTY);
	}

	// Return newly created Vector2 with components set to our normalized Point2f
	return Vector2(m_Normalized);
}

const Vector2& Vector2::Normalize()
{
	// Make sure magnitude is up to date
	// Normalize components
    if (GetMagnitude() == 0.0f)
    {
        SetXY(0.0f, 0.0f);
    }
    else
    {
		// Done manually since we know the outcome
		// Set Components
        m_X = m_X / m_Magnitude;
        m_Y = m_Y / m_Magnitude;

		// Set cached values
		m_MagnitudeSquared = 1.0f;
		m_Magnitude = 1.0f;
		m_Normalized = { m_X, m_Y };

		// Clean out flags
		Helpers::BitMaskHelpers::RemoveFlagsFromMask(m_DirtynessMask, c_ALL_DIRTY);
    }

	// Return ourselves after we've been normalized
	return *this;
}

// For use when setting member variables that change integrity of object
// Let's us know that we need to recalculate certain member variables
// Only to be used when setting X and Y
template<typename T>
void Vector2::SetMemberIntegrityCheck(T& member, const T &value)
{
	// If the values changed, all calculated members are now dirty
	// If values did not change, dirtyness level remains the same
	if (member != value)
		m_DirtynessMask = c_ALL_DIRTY;

	member = value;
}