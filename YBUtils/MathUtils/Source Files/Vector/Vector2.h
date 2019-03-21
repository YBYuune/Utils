#ifndef __VECTOR2_H__
#define __VECTOR2_H__

namespace YBMath
{
    struct Vector2
    {
	////      ---- MEMBER FUNCTIONS ----
    public:
        Vector2();
        Vector2(float x);
        Vector2(float x, float y);
        ~Vector2();

		// Getters and Setters
		void SetXY(float x, float y);

		float GetX() const;
		void SetX(float x);

		float GetY() const;
		void SetY(float y);

		float GetMagnitude() const;

	private:
		template<typename T>
		void SetMemberIntegrityCheck(T& member, const T &value);


	////      ---- STATIC FUNCTIONS ----
	public:
		static float GetMagnitude(const Vector2 &v);


	private:
		template <typename T>
		static bool WillMakeDirty(const T &original, const T &value);


    
	////      ---- MEMBER VARIABLES ----
	private:
		// Values that will be accessible outside the class
		float m_X;
		float m_Y;
		mutable float m_Magnitude;

		// Variable for state of object
		bool m_IsDirty;
    };
}



#endif