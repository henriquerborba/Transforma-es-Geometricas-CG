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
    vector<ObjectPart *> parts;
    vector<Matrix> stack;

    void draw();
};

#endif // __STICKMAN_H__ INCLUDED