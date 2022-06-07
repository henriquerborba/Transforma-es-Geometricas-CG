#ifndef STICKMAN_PART_H_INCLUDED
#define STICKMAN_PART_H_INCLUDED

#include "../../utils/vector2.h"

class StickmanPart
{
public:
    StickmanPart(float height, float width, Vector2 position, float rotation);
    ~StickmanPart();
    void draw();
    void localtransform();
    float rotation;
    Vector2 pivot;
    float width;
    float height;
};

#endif // STICKMAN_PART_H_INCLUDED