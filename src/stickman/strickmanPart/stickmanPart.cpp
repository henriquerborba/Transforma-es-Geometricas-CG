#include "stickmanPart.h"

StickmanPart::StickmanPart(float height, float width, Vector2 position, float rotation)
{
    this->height = height;
    this->width = width;
    this->pivot = position;
    this->rotation = rotation;
}

StickmanPart::~StickmanPart()
{
}

void StickmanPart::localtransform()
{
}