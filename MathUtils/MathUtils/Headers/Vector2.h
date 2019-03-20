#ifndef __VECTOR2_H__
#define __VECTOR2_H__

namespace YBMath
{
    struct Vector2
    {
    public:
        Vector2();
        Vector2(float x);
        Vector2(float x, float y);
        ~Vector2();



        ////      ---- MEMBER VARIABLES ----
    public:
        float x;
        float y;

    };
}



#endif