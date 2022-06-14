#include "stickman.h"

Stickman::Stickman()
{
    // Modelagem da cabeça e dos braços
    ObjectPart *head = new ObjectPart(8, 8, Vector2(10, 120), 0, 20);
    ObjectPart *body = new ObjectPart(100, 1, Vector2(-10, 0), 80, 4);
    ObjectPart *arm1 = new ObjectPart(60, 1, Vector2(0, 70), -30, 4);
    ObjectPart *arm2 = new ObjectPart(50, 1, Vector2(0, 70), 30, 4);

    parts = {head, body, arm1};

    // Modelagem dos pernas
    ObjectPart *femur1 = new ObjectPart(50, 1, Vector2(-10, 0), 0, 4);
    ObjectPart *tibia1 = new ObjectPart(50, 1, Vector2(25, 0), 0, 4);

    leg1 = {femur1, tibia1};

    ObjectPart *femur2 = new ObjectPart(50, 1, Vector2(-10, 0), 0, 4);
    ObjectPart *tibia2 = new ObjectPart(50, 1, Vector2(25, 0), 0, 4);

    leg2 = {femur2, tibia2};
}

void Stickman::drawJoint(vector<ObjectPart *> parts)
{
    vector<Matrix> tmpStack;

    for (auto part : parts)
    {
        if (!tmpStack.empty())
        {
            part->wtransform(tmpStack.back());
        }
        part->draw();
        tmpStack.push_back(part->localTransformation);
    }
}

void Stickman::draw()
{
    drawJoint(leg1);
    drawJoint(leg2);
    for (auto part : parts)
    {
        part->draw();
    }
}