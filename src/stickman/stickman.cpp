#include "stickman.h"

Stickman::Stickman()
{
    ObjectPart *head = new ObjectPart(8, 8, Vector2(14, 150), 0, 20);
    ObjectPart *body = new ObjectPart(130, 1, Vector2(-10, 0), 80, 4);
    ObjectPart *arm1 = new ObjectPart(50, 1, Vector2(0, 50), 0, 4);
    ObjectPart *leg1 = new ObjectPart(66, 1, Vector2(-10, 0), -5, 4);
    ObjectPart *leg2 = new ObjectPart(66, 1, Vector2(-10, 0), -40, 4);

    parts = {head, body, arm1, leg1, leg2};

    // ObjectPart *trace = new ObjectPart(200, 100, Vector2(0, 0), 30, 4);

    // parts = {trace};
}

void Stickman::draw()
{
    vector<Matrix> tmpStack = stack;

    for (auto part : parts)
    {
        if (!tmpStack.empty())
        {
            part->wtransform(tmpStack.back());
        }
        part->draw();
        tmpStack.push_back(part->localTransformation);
    }

    stack = tmpStack;
}