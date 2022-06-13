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
    vector<Vector2> transformedVertices;
    void draw();
    void scale(float width, float height);
    void rotate(float angle);
    void translate(float positionX, float positionY);
    void addTransformation(Matrix m);
    void transform();
    float angle = 0;
    float positionX = 0;
    float positionY = 0;
    float width = 1;
    float height = 1;

private:
    Matrix mtransformation = Matrix::createIdentity(3);

    Matrix mscale = Matrix::createIdentity(3);

    Matrix mrotate = Matrix::createIdentity(3);

    Matrix mtranslate = Matrix::createIdentity(3);

    Matrix wtransformation = Matrix::createIdentity(3);
};

#endif // POLYGON_H_INCLUDED
