#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include "../canvas/gl_canvas2d.h"
#include "../utils/vector2.h"
#include "../matrix/matrix.h"
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
    Matrix mtransformation = Matrix::createIdentity(3);

    Matrix mscale = Matrix::createIdentity(3);

    Matrix mrotate = Matrix::createIdentity(3);

    Matrix mtranslate = Matrix::createIdentity(3);
};

#endif // POLYGON_H_INCLUDED
