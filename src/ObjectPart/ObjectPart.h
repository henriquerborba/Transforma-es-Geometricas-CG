#ifndef STICKMAN_PART_H_INCLUDED
#define STICKMAN_PART_H_INCLUDED

#include "../utils/vector2.h"
#include "../polygon/polygon.h"
#include "../matrix/matrix.h"

class ObjectPart
{
public:
    ObjectPart(float height, float width, Vector2 position, float rotation, int vertices);
    ObjectPart(float height, float width, int sides);
    ~ObjectPart();

    void draw();

    Polygon2d *polygon;

    Matrix mtransformation = Matrix::createIdentity(3);
    Matrix wtransformation = Matrix::createIdentity(3);
    Matrix localTransformation = Matrix::createIdentity(3);

    void localtransform();
    void wtransform(Matrix matrix);
    float Sx = 0, Sy = 0, translateX = 0, translateY = 0;
    float rotation;
    Vector2 pivot;
    int vertices;
    float width;
    float height;
};

#endif // STICKMAN_PART_H_INCLUDED