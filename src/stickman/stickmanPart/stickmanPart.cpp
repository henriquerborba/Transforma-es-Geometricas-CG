#include "stickmanPart.h"
#include "../../GUI/GUI.h"

StickmanPart::StickmanPart(float width, float height, Vector2 position, float rotation, int vertices)
{
    this->height = height;
    this->width = width;
    this->pivot = position;
    this->rotation = rotation;
    this->polygon = new Polygon2d(vertices);
    Vector2 aux = polygon->vertices[1] - polygon->vertices[0];
    Sx = width / aux.module();
    Sy = height / aux.module();
    translateX = width / 2 + pivot.x;
    translateY = 0 + pivot.y;
}

StickmanPart::~StickmanPart()
{
}

void StickmanPart::draw()
{
    localtransform();
    polygon->draw();
    mtransformation = Matrix::createIdentity(3);
}

void StickmanPart::localtransform()
{
    mtransformation *= Matrix::translate(translateX, translateY);
    mtransformation *= Matrix::translate(width / 2, 0).inverse();
    mtransformation *= Matrix::rotate(rotation);
    mtransformation *= Matrix::translate(width / 2, 0);
    mtransformation *= Matrix::scale(Sx, Sy);
    polygon->addTransformation(mtransformation);
}
