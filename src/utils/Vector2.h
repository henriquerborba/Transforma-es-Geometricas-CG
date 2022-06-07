#ifndef __VECTOR_2_H__
#define __VECTOR_2_H__

#include <math.h>
#include <stdio.h>
#define M_PI 3.14159265358979323846 /* pi */

class Vector2
{
public:
    float x, y;

    Vector2()
    {
        x = y = 0;
    }

    Vector2(float _x, float _y)
    {
        x = _x;
        y = _y;
    }

    void set(float _x, float _y)
    {
        x = _x;
        y = _y;
    }

    void translate(float _x, float _y)
    {
        x += _x;
        y += _y;
    }

    void rotate(float degree)
    {
        float rad = degree * M_PI / 180;
        float cos = cosf(rad);
        float sin = sinf(rad);
        float newX = x * cos - y * sin;
        float newY = x * sin + y * cos;
        x = newX;
        y = newY;
    }

    void normalize()
    {
        float norm = (float)sqrt(x * x + y * y);

        if (norm == 0.0)
        {
            printf("\n\nNormalize::Divisao por zero");
            x = 1;
            y = 1;
            return;
        }
        x /= norm;
        y /= norm;
    }

    float module()
    {
        return sqrt(x * x + y * y);
    }

    Vector2 operator-(const Vector2 &v)
    {
        Vector2 aux(x - v.x, y - v.y);
        return (aux);
    }

    Vector2 operator+(const Vector2 &v)
    {
        Vector2 aux(x + v.x, y + v.y);
        return (aux);
    }

    // Adicionem os demais overloads de operadores aqui.
    Vector2 operator*(float s)
    {
        Vector2 aux(x * s, y * s);
        return (aux);
    }

    Vector2 operator*=(float s)
    {
        x *= s;
        y *= s;
        return *this;
    }
};

#endif
