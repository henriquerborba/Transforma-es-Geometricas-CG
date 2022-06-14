#ifndef __STICKMAN_H__
#define __STICKMAN_H__

#include <stdio.h>
#include "../ObjectPart/ObjectPart.h"
#include <vector>

using namespace std;

class Stickman
{
public:
    Stickman();

    ~Stickman();
    vector<ObjectPart *> leg1;
    vector<ObjectPart *> leg2;
    vector<ObjectPart *> parts;
    vector<Matrix> stack;

    void draw();
    void drawJoint(vector<ObjectPart *> parts);
};

#endif // __STICKMAN_H__ INCLUDED