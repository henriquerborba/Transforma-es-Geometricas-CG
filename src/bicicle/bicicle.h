#ifndef __BICICLE_H__
#define __BICICLE_H__

#include <stdio.h>
#include "../ObjectPart/ObjectPart.h"
#include <vector>
#include "../polygon/polygon.h"

using namespace std;

class Bicicle
{
public:
    Bicicle();

    ~Bicicle();
    vector<ObjectPart *> radiusWheel1;
    vector<ObjectPart *> radiusWheel2;
    vector<ObjectPart *> frame;
    vector<ObjectPart *> parts;
    Polygon2d *circleWheel1;
    Polygon2d *circleWheel2;

    void draw();
    void drawJoint(vector<ObjectPart *> parts);
};

#endif // __BICICLE_H__ INCLUDED