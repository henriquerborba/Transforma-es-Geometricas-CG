#include "./ObjectPart.h"

ObjectPart::ObjectPart(float width, float height, Vector2 position, float rotation, int vertices)
{
    this->height = height;
    this->width = width;
    this->pivot = position;
    this->rotation = rotation;
    this->polygon = new Polygon2d(vertices);
}

ObjectPart::~ObjectPart()
{
}

void ObjectPart::draw()
{
    wtransform(wtransformation);
    localtransform();
    polygon->addTransformation(mtransformation);
    polygon->draw();
    mtransformation = Matrix::createIdentity(3);
}

void ObjectPart::wtransform(Matrix matrix)
{
    mtransformation = Matrix::createIdentity(3);
    this->wtransformation = matrix;
    mtransformation *= matrix;
}

void ObjectPart::localtransform()
{
    Vector2 aux = polygon->vertices[1] - polygon->vertices[0];
    Sx = width / aux.module();
    Sy = height / aux.module();
    translateX = width / 2 + pivot.x;
    translateY = 0 + pivot.y;
    polygon->scale(Sx, Sy);
    mtransformation *= Matrix::translate(translateX, translateY);
    mtransformation *= Matrix::translate(-width / 2, 0);
    mtransformation *= Matrix::rotate(rotation);
    mtransformation *= Matrix::translate(width / 2, 0);
    localTransformation = mtransformation;
}
