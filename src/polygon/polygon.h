#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include "../canvas/gl_canvas2d.h"
#include "../utils/vector2.h"
#include <iostream>
#include <vector>

using namespace std;

class Polygon2d
{
public:
    Polygon2d(int vertices = 4);
    ~Polygon2d();
    vector<Vector2> vertices;
    void draw();
    void scale();
    void rotate();
    void translate();
    void transform();
    void setTranslation(float x, float y);
    void setScale(float x, float y);
    void setRotation(float angle);
    float degrees = PI_2;
    float tx = 0;
    float ty = 0;
    float sx = 1;
    float sy = 1;

private:
    float mtransformation[3][3] = {
        {1.0, 0, 0},
        {0, 1.0, 0},
        {0, 0, 1.0},
    };

    float mtranslate[3][3] = {
        {1.0, 0, tx},
        {0, 1.0, ty},
        {0, 0, 1.0},
    };

    float mrotate[3][3] = {
        {cos(degrees), -sin(degrees), 0},
        {sin(degrees), cos(degrees), 0},
        {0, 0, 1.0},
    };

    float mscale[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1.0},
    };
};

#endif // POLYGON_H_INCLUDED
